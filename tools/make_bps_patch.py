#!/usr/bin/env python3
"""Create and verify a BPS patch without distributing either ROM image."""
from __future__ import annotations

import argparse
import hashlib
import struct
import sys
import zlib
from pathlib import Path


def encode_number(value: int) -> bytes:
    """Encode an unsigned integer using the BPS variable-length format."""
    if value < 0:
        raise ValueError("BPS integers must be non-negative")
    output = bytearray()
    while True:
        byte = value & 0x7F
        value >>= 7
        if value == 0:
            output.append(byte | 0x80)
            break
        output.append(byte)
        value -= 1
    return bytes(output)


def decode_number(data: bytes, offset: int) -> tuple[int, int]:
    value = 0
    shift = 1
    while True:
        if offset >= len(data):
            raise ValueError("Unexpected end of BPS variable integer")
        byte = data[offset]
        offset += 1
        value += (byte & 0x7F) * shift
        if byte & 0x80:
            return value, offset
        shift <<= 7
        value += shift


def create_patch(source: bytes, target: bytes) -> bytes:
    """Create a compact BPS patch using SourceRead and TargetRead actions."""
    patch = bytearray(b"BPS1")
    patch.extend(encode_number(len(source)))
    patch.extend(encode_number(len(target)))
    patch.extend(encode_number(0))  # no metadata

    index = 0
    while index < len(target):
        source_matches = index < len(source) and source[index] == target[index]
        end = index + 1
        while end < len(target):
            next_matches = end < len(source) and source[end] == target[end]
            if next_matches != source_matches:
                break
            end += 1

        length = end - index
        action_type = 0 if source_matches else 1
        patch.extend(encode_number(((length - 1) << 2) | action_type))
        if not source_matches:
            patch.extend(target[index:end])
        index = end

    patch.extend(struct.pack("<I", zlib.crc32(source) & 0xFFFFFFFF))
    patch.extend(struct.pack("<I", zlib.crc32(target) & 0xFFFFFFFF))
    patch.extend(struct.pack("<I", zlib.crc32(patch) & 0xFFFFFFFF))
    return bytes(patch)


def apply_patch(source: bytes, patch: bytes) -> bytes:
    """Apply the supported BPS actions and validate all BPS checksums."""
    if len(patch) < 16 or patch[:4] != b"BPS1":
        raise ValueError("Not a valid BPS1 patch")

    expected_source_crc, expected_target_crc, expected_patch_crc = struct.unpack("<III", patch[-12:])
    if (zlib.crc32(source) & 0xFFFFFFFF) != expected_source_crc:
        raise ValueError("Source ROM checksum does not match this patch")
    if (zlib.crc32(patch[:-4]) & 0xFFFFFFFF) != expected_patch_crc:
        raise ValueError("BPS patch checksum is invalid")

    offset = 4
    source_size, offset = decode_number(patch, offset)
    target_size, offset = decode_number(patch, offset)
    metadata_size, offset = decode_number(patch, offset)
    if source_size != len(source):
        raise ValueError(f"Source size mismatch: patch expects {source_size}, got {len(source)}")
    action_end = len(patch) - 12
    if offset + metadata_size > action_end:
        raise ValueError("Invalid BPS metadata length")
    offset += metadata_size

    output = bytearray()
    while offset < action_end and len(output) < target_size:
        action, offset = decode_number(patch, offset)
        action_type = action & 3
        length = (action >> 2) + 1

        if action_type == 0:  # SourceRead: copy from source at current output offset.
            source_offset = len(output)
            chunk = source[source_offset:source_offset + length]
            if len(chunk) != length:
                raise ValueError("SourceRead extends beyond the source ROM")
            output.extend(chunk)
        elif action_type == 1:  # TargetRead: literal bytes stored in the patch.
            if offset + length > action_end:
                raise ValueError("TargetRead extends beyond the BPS action data")
            output.extend(patch[offset:offset + length])
            offset += length
        else:
            raise ValueError(f"Unsupported BPS action type {action_type}")

    if len(output) != target_size:
        raise ValueError(f"Patch produced {len(output)} bytes, expected {target_size}")
    if (zlib.crc32(output) & 0xFFFFFFFF) != expected_target_crc:
        raise ValueError("Patched target checksum is invalid")
    return bytes(output)


def self_test() -> None:
    values = [0, 1, 2, 127, 128, 129, 255, 256, 16384, 1 << 24, (1 << 32) - 1]
    for value in values:
        decoded, end = decode_number(encode_number(value), 0)
        if decoded != value or end != len(encode_number(value)):
            raise AssertionError(f"BPS integer round-trip failed for {value}")

    cases = [
        (b"", b""),
        (b"abc", b"abc"),
        (b"abcdef", b"abXdef!"),
        (b"larger source", b"x"),
        (bytes(range(256)) * 4, bytes(range(256)) * 2 + b"JAREDS EMERALD" + bytes(range(128))),
        (b"", b"target is longer than source"),
    ]
    for source, target in cases:
        patch = create_patch(source, target)
        if apply_patch(source, patch) != target:
            raise AssertionError("BPS self-test produced the wrong target")
    print(f"PASS: BPS generator self-test ({len(values)} integer cases, {len(cases)} patch cases)")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--self-test", action="store_true", help="run built-in BPS format tests")
    parser.add_argument("source", nargs="?", help="clean source ROM")
    parser.add_argument("target", nargs="?", help="custom target ROM")
    parser.add_argument("output", nargs="?", help="output BPS patch path")
    args = parser.parse_args()

    if args.self_test:
        self_test()
        return 0
    if not all((args.source, args.target, args.output)):
        parser.error("source, target, and output are required unless --self-test is used")

    source_path, target_path, output_path = map(Path, (args.source, args.target, args.output))
    source = source_path.read_bytes()
    target = target_path.read_bytes()
    patch = create_patch(source, target)
    if apply_patch(source, patch) != target:
        raise SystemExit("ERROR: generated BPS patch did not recreate the target ROM")
    output_path.write_bytes(patch)

    print("PASS: BPS patch generated and verified")
    print(f"Source SHA-1: {hashlib.sha1(source).hexdigest()}")
    print(f"Target SHA-1: {hashlib.sha1(target).hexdigest()}")
    print(f"Patch SHA-256: {hashlib.sha256(patch).hexdigest()}")
    print(f"Patch size: {len(patch)} bytes")
    return 0


if __name__ == "__main__":
    sys.exit(main())
