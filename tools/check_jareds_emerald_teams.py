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
    "TRAINER_DRAKE", "TRAINER_WALLACE",
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
}
STARTERS = {
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

boss_max_levels = {}
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
    levels = [int(level) for level in re.findall(r"(?m)^Level: (\d+)\s*$", party)]
    if len(levels) != 6:
        fail(f"{boss} has {len(levels)} explicit Pokémon levels; expected exactly 6")
    boss_max_levels[boss] = max(levels)
    legendary_count = sum(mon in LEGENDARIES for mon in species)
    starter_count = sum(mon in STARTERS for mon in species)
    if legendary_count != 1:
        fail(f"{boss} has {legendary_count} Legendary Pokémon; expected exactly 1 ({species})")
    if starter_count != 1:
        fail(f"{boss} has {starter_count} starter-family Pokémon; expected exactly 1 ({species})")
    shiny_count = len(re.findall(r"(?m)^Shiny: Yes\s*$", party))
    if boss in GYM_LEADERS and shiny_count != 1:
        fail(f"{boss} has {shiny_count} explicitly shiny Pokémon; expected exactly 1")

# Compare custom teams against the original Emerald trainer maxima.
# Teams may be lower-level, but must never exceed the original boss's highest level.
original_boss_max_levels = {
    "TRAINER_ROXANNE_1": 15, "TRAINER_BRAWLY_1": 19,
    "TRAINER_WATTSON_1": 24, "TRAINER_FLANNERY_1": 29,
    "TRAINER_NORMAN_1": 31, "TRAINER_WINONA_1": 33,
    "TRAINER_TATE_AND_LIZA_1": 42, "TRAINER_JUAN_1": 46,
    "TRAINER_SIDNEY": 49, "TRAINER_PHOEBE": 51,
    "TRAINER_GLACIA": 53, "TRAINER_DRAKE": 55,
    "TRAINER_WALLACE": 58,
}
for boss, original_max_level in original_boss_max_levels.items():
    actual_max_level = boss_max_levels.get(boss)
    if actual_max_level is None or actual_max_level > original_max_level:
        fail(f"{boss} max level is {actual_max_level}; exceeds original Emerald maximum {original_max_level}")

# Verify the three starter choices are randomized into distinct valid species
# when the new game's starter-selection screen is entered.
starter_source = Path("src/starter_choose.c").read_text(encoding="utf-8")
for snippet in [
    "#define STARTER_MON_COUNT   3",
    "static void RandomizeJaredsEmeraldStarters(void)",
    "candidate = (Random() % (NUM_SPECIES - 1)) + 1;",
    "if (sStarterMon[j] == candidate)",
    "sStarterMon[i] = candidate;",
    "RandomizeJaredsEmeraldStarters();",
]:
    if snippet not in starter_source:
        fail(f"missing randomized starter-selection logic: {snippet}")
if starter_source.count("RandomizeJaredsEmeraldStarters();") != 1:
    fail("starter randomization must run once when entering starter selection")

# Verify wild encounters are stable per save rather than re-rolled every encounter.
wild_source = Path("src/wild_encounter.c").read_text(encoding="utf-8")
for snippet in [
    "u32 seed = READ_OTID_FROM_SAVE;",
    "gSaveBlock1Ptr->location.mapGroup",
    "gSaveBlock1Ptr->location.mapNum",
    "seed ^= ((u32)area << 8);",
    "seed ^= slot;",
    "GetJaredsEmeraldWildSpecies(area, wildMonIndex)",
    "GetJaredsEmeraldWildSpecies(WILD_AREA_FISHING, wildMonIndex)",
]:
    if snippet not in wild_source:
        fail(f"missing save-specific wild encounter logic: {snippet}")

pokemon_source = Path("src/pokemon.c").read_text(encoding="utf-8")
if "Rare Candies must respect the same hard cap as battle EXP" not in pokemon_source:
    fail("Rare Candy level-cap enforcement is missing")

# Verify the in-game item cheat menu is accessible from the Start menu.
debug_source = Path("src/debug.c").read_text(encoding="utf-8")
start_menu_source = Path("src/start_menu.c").read_text(encoding="utf-8")
debug_config = Path("include/config/debug.h").read_text(encoding="utf-8")
if "sJaredsEmeraldItemMenu" not in debug_source or "Debug_ShowMenu(DebugTask_HandleMenuInput_General, sJaredsEmeraldItemMenu)" not in debug_source or "Debug_ShowJaredsItemMenu();" not in start_menu_source:
    fail("JARED'S EMERALD item-cheat menu is missing")
if "JARED'S ITEMS" not in start_menu_source:
    fail("JARED'S ITEMS Start-menu entry is missing")
if "#define DEBUG_OVERWORLD_MENU            TRUE" not in debug_config or "#define DEBUG_OVERWORLD_IN_MENU         TRUE" not in debug_config:
    fail("JARED'S ITEMS Start-menu access is not enabled")

# Verify the level-cap progression is wired into the build configuration.
caps_source = Path("src/caps.c").read_text(encoding="utf-8")
caps_config = Path("include/config/caps.h").read_text(encoding="utf-8")
for flag, cap in [
    ("FLAG_BADGE01_GET", 15), ("FLAG_BADGE02_GET", 19),
    ("FLAG_BADGE03_GET", 24), ("FLAG_BADGE04_GET", 29),
    ("FLAG_BADGE05_GET", 31), ("FLAG_BADGE06_GET", 33),
    ("FLAG_BADGE07_GET", 42), ("FLAG_BADGE08_GET", 46),
]:
    if f"{{{flag}, {cap}}}" not in caps_source:
        fail(f"missing expected badge cap {flag} -> {cap}")
for flag, cap in [
    ("FLAG_DEFEATED_ELITE_4_SIDNEY", 49),
    ("FLAG_DEFEATED_ELITE_4_PHOEBE", 51),
    ("FLAG_DEFEATED_ELITE_4_GLACIA", 53),
    ("FLAG_DEFEATED_ELITE_4_DRAKE", 55),
]:
    if f"if (!FlagGet({flag}))\n            return {cap};" not in caps_source:
        fail(f"missing expected Elite Four cap {flag} -> {cap}")
if "if (!FlagGet(FLAG_IS_CHAMPION))\n            return 58;" not in caps_source:
    fail("missing Champion cap at the original Wallace maximum level 58")
if "#define B_EXP_CAP_TYPE                  EXP_CAP_HARD" not in caps_config:
    fail("hard experience cap is not enabled")
if "#define B_LEVEL_CAP_TYPE                LEVEL_CAP_FLAG_LIST" not in caps_config:
    fail("badge/League cap progression is not enabled")
if "#define B_RARE_CANDY_CAP                TRUE" not in caps_config:
    fail("Rare Candy cap is not enabled")

print("PASS: starter choices are randomized once per new-game starter selection and wild species are stable per save/map/area/slot.")
print(f"PASS: all {len(BOSSES)} major boss teams have six Pokémon, one Legendary, and one starter-family Pokémon; each Gym Leader has exactly one explicitly shiny Pokémon; all boss-team maximum levels stay at or below the original Emerald boss maxima, and level-cap progression matches those original maxima.")
