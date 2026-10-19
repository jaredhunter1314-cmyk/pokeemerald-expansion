#!/usr/bin/env python3
"""Static acceptance checks for JARED'S EMERALD major boss teams."""
from pathlib import Path
import re
import sys

PARTY_FILE = Path("src/data/trainers.party")
BOSSES = {
    "TRAINER_ROXANNE_1", "TRAINER_BRAWLY_1", "TRAINER_WATTSON_1",
    "TRAINER_FLANNERY_1", "TRAINER_NORMAN_1", "TRAINER_WINONA_1",
    "TRAINER_TATE_AND_LIZA_1", "TRAINER_JUAN_1",
    "TRAINER_SIDNEY", "TRAINER_PHOEBE", "TRAINER_GLACIA",
    "TRAINER_DRAKE", "TRAINER_STEVEN",
}
LEGENDARIES = {
    "Articuno", "Zapdos", "Moltres", "Mewtwo", "Mew", "Raikou",
    "Entei", "Suicune", "Lugia", "Ho-Oh", "Celebi", "Regirock",
    "Regice", "Registeel", "Latias", "Latios", "Kyogre", "Groudon",
    "Rayquaza", "Jirachi", "Deoxys", "Uxie", "Mesprit", "Azelf",
    "Dialga", "Palkia", "Heatran", "Regigigas", "Giratina", "Cresselia",
    "Phione", "Manaphy", "Darkrai", "Shaymin", "Arceus", "Victini",
    "Cobalion", "Terrakion", "Virizion", "Tornadus", "Thundurus",
    "Reshiram", "Zekrom", "Landorus", "Kyurem", "Keldeo", "Meloetta",
    "Genesect", "Xerneas", "Yveltal", "Zygarde", "Diancie", "Hoopa",
    "Volcanion", "Type: Null", "Silvally", "Tapu Koko", "Tapu Lele",
    "Tapu Bulu", "Tapu Fini", "Cosmog", "Cosmoem", "Solgaleo",
    "Lunala", "Necrozma", "Magearna", "Marshadow", "Zeraora",
    "Zacian", "Zamazenta", "Eternatus", "Kubfu", "Urshifu",
    "Regieleki", "Regidrago", "Glastrier", "Spectrier", "Calyrex",
    "Enamorus", "Wo-Chien", "Chien-Pao", "Ting-Lu", "Chi-Yu",
    "Koraidon", "Miraidon", "Walking Wake", "Iron Leaves",
    "Gouging Fire", "Raging Bolt", "Iron Boulder", "Iron Crown",
}
GYM_LEADERS = {
    "TRAINER_ROXANNE_1", "TRAINER_BRAWLY_1", "TRAINER_WATTSON_1",
    "TRAINER_FLANNERY_1", "TRAINER_NORMAN_1", "TRAINER_WINONA_1",
    "TRAINER_TATE_AND_LIZA_1", "TRAINER_JUAN_1",
}\nSTARTERS = {
    "Bulbasaur", "Ivysaur", "Venusaur", "Charmander", "Charmeleon",
    "Charizard", "Squirtle", "Wartortle", "Blastoise", "Chikorita",
    "Bayleef", "Meganium", "Cyndaquil", "Quilava", "Typhlosion",
    "Totodile", "Croconaw", "Feraligatr", "Treecko", "Grovyle",
    "Sceptile", "Torchic", "Combusken", "Blaziken", "Mudkip",
    "Marshtomp", "Swampert", "Turtwig", "Grotle", "Torterra",
    "Chimchar", "Monferno", "Infernape", "Piplup", "Prinplup",
    "Empoleon", "Snivy", "Servine", "Serperior", "Tepig", "Pignite",
    "Emboar", "Oshawott", "Dewott", "Samurott", "Chespin",
    "Quilladin", "Chesnaught", "Fennekin", "Braixen", "Delphox",
    "Froakie", "Frogadier", "Greninja", "Rowlet", "Dartrix",
    "Decidueye", "Litten", "Torracat", "Incineroar", "Popplio",
    "Brionne", "Primarina", "Grookey", "Thwackey", "Rillaboom",
    "Scorbunny", "Raboot", "Cinderace", "Sobble", "Drizzile",
    "Inteleon", "Sprigatito", "Floragato", "Meowscarada",
    "Fuecoco", "Crocalor", "Skeledirge", "Quaxly", "Quaxwell",
    "Quaquaval",
}

def fail(message: str) -> None:
    print(f"FAIL: {message}", file=sys.stderr)
    raise SystemExit(1)

text = PARTY_FILE.read_text(encoding="utf-8")
blocks = {}
matches = list(re.finditer(r"^=== (TRAINER_[A-Z0-9_]+) ===\s*$", text, re.M))
for i, match in enumerate(matches):
    name = match.group(1)
    end = matches[i + 1].start() if i + 1 < len(matches) else len(text)
    blocks[name] = text[match.end():end]

for boss in sorted(BOSSES):
    if boss not in blocks:
        fail(f"missing boss definition {boss}")
    block = blocks[boss]
    # The header ends at the first blank line; Pokémon entries are plain lines
    # without a field colon or move-list prefix.
    party = block.split("\n\n", 1)[1] if "\n\n" in block else ""
    species = []
    for line in party.splitlines():
        line = line.strip()
        if not line or line.startswith("-") or ":" in line or line.startswith("==="):
            continue
        species.append(line.split(" @ ", 1)[0])
    if len(species) != 6:
        fail(f"{boss} has {len(species)} Pokémon; expected exactly 6")
    legendary_count = sum(mon in LEGENDARIES for mon in species)
    starter_count = sum(mon in STARTERS for mon in species)
    if legendary_count != 1:
        fail(f"{boss} has {legendary_count} Legendary Pokémon; expected exactly 1 ({species})")
    if starter_count != 1:
        fail(f"{boss} has {starter_count} starter-family Pokémon; expected exactly 1 ({species})")
    shiny_count = len(re.findall(r"(?m)^Shiny: true\s*$", party))
    if boss in GYM_LEADERS and shiny_count != 1:
        fail(f"{boss} has {shiny_count} explicitly shiny Pokémon; expected exactly 1")

# Verify the level-cap progression is wired into the build configuration.
caps_source = Path("src/caps.c").read_text(encoding="utf-8")
caps_config = Path("include/config/caps.h").read_text(encoding="utf-8")
for flag, cap in [
    ("FLAG_BADGE01_GET", 15), ("FLAG_BADGE02_GET", 19),
    ("FLAG_BADGE03_GET", 24), ("FLAG_BADGE04_GET", 29),
    ("FLAG_BADGE05_GET", 31), ("FLAG_BADGE06_GET", 33),
    ("FLAG_BADGE07_GET", 36), ("FLAG_BADGE08_GET", 41),
]:
    if f"{{{flag}, {cap}}}" not in caps_source:
        fail(f"missing expected badge cap {flag} -> {cap}")
for flag, cap in [
    ("FLAG_DEFEATED_ELITE_4_SIDNEY", 52),
    ("FLAG_DEFEATED_ELITE_4_PHOEBE", 54),
    ("FLAG_DEFEATED_ELITE_4_GLACIA", 56),
    ("FLAG_DEFEATED_ELITE_4_DRAKE", 58),
]:
    if f"if (!FlagGet({flag}))\\n            return {cap};" not in caps_source:
        fail(f"missing expected Elite Four cap {flag} -> {cap}")
if "#define B_EXP_CAP_TYPE                  EXP_CAP_HARD" not in caps_config:
    fail("hard experience cap is not enabled")
if "#define B_LEVEL_CAP_TYPE                LEVEL_CAP_FLAG_LIST" not in caps_config:
    fail("badge/League cap progression is not enabled")
if "#define B_RARE_CANDY_CAP                TRUE" not in caps_config:
    fail("Rare Candy cap is not enabled")

print(f"PASS: all {len(BOSSES)} major boss teams have six Pokémon, one Legendary, and one starter-family Pokémon; each Gym Leader has exactly one explicitly shiny Pokémon; level-cap config and progression are enabled.")
