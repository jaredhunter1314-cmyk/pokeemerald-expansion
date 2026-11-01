    // Skyrim enemy clones (generated from base species entries)
    [SPECIES_DRAUGR] =
    {
        .baseHP        = 40,
        .baseAttack    = 80,
        .baseDefense   = 100,
        .baseSpeed     = 20,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_ROCK, TYPE_GROUND),
        .catchRate = 255,
    #if P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 60,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 73,
    #else
        .expYield = 86,
    #endif
        .evYield_Defense = 1,
        .itemRare = ITEM_EVERSTONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_STURDY, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Draugr"),
        .cryId = CRY_GEODUDE,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Rock"),
        .height = 4,
        .weight = 200,
        .description = COMPOUND_STRING(
            "It climbs mountain paths using only the\n"
            "power of its arms. Because they look just\n"
            "like boulders lining paths, hikers may step\n"
            "on them without noticing."),
        .pokemonScale = 347,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 16 : 10,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 2, SHADOW_SIZE_M)
        FOOTPRINT(Geodude)
        OVERWORLD(
            sPicTable_Geodude,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Geodude,
            gShinyOverworldPalette_Geodude
        )
        .levelUpLearnset = sGeodudeLevelUpLearnset,
        .teachableLearnset = sGeodudeTeachableLearnset,
        .eggMoveLearnset = sGeodudeEggMoveLearnset,
        .frontPic = gMonFrontPic_SkyDraugr,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .backPic = gMonBackPic_SkyDraugr,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_SkyDraugr,
        .shinyPalette = gMonShinyPalette_SkyDraugr,
        .iconSprite = gMonIcon_SkyDraugr,
        .iconPalIndex = 2,
    },
    [SPECIES_SKELETON] =
    {
        .baseHP        = 45,
        .baseAttack    = 95,
        .baseDefense   = 50,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ROCK, TYPE_BUG),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 71,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 99,
    #else
        .expYield = 119,
    #endif
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_BATTLE_ARMOR, ABILITY_NONE, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Skeleton"),
        .cryId = CRY_ANORITH,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Old Shrimp"),
        .height = 7,
        .weight = 125,
        .description = COMPOUND_STRING(
            "It was resurrected from a fossil using the\n"
            "power of science. It swims by undulating\n"
            "the eight wings at its sides. They were\n"
            "feet that adapted to life in the sea."),
        .pokemonScale = 296,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_TWIST,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 4, SHADOW_SIZE_S)
        FOOTPRINT(Anorith)
        OVERWORLD(
            sPicTable_Anorith,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Anorith,
            gShinyOverworldPalette_Anorith
        )
        .levelUpLearnset = sAnorithLevelUpLearnset,
        .teachableLearnset = sAnorithTeachableLearnset,
        .eggMoveLearnset = sAnorithEggMoveLearnset,
        .frontPic = gMonFrontPic_SkySkeleton,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .backPic = gMonBackPic_SkySkeleton,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_SkySkeleton,
        .shinyPalette = gMonShinyPalette_SkySkeleton,
        .iconSprite = gMonIcon_SkySkeleton,
        .iconPalIndex = 2,
    },
    [SPECIES_FROSTBITE_SPIDER] =
    {
        .baseHP        = 40,
        .baseAttack    = 60,
        .baseDefense   = 40,
        .baseSpeed     = 30,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_BUG, TYPE_POISON),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 50 : 54,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_INSOMNIA, ABILITY_SNIPER },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Frost Spider"),
        .cryId = CRY_SPINARAK,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("String Spit"),
        .height = 5,
        .weight = 85,
        .description = COMPOUND_STRING(
            "The web it spins can be considered its\n"
            "second nervous system. It is said that a\n"
            "Spinarak determines its prey by the tiny\n"
            "vibrations it feels through the web."),
        .pokemonScale = 414,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
        ),
        .frontAnimId = ANIM_CIRCLE_C_CLOCKWISE_SLOW,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, -8, SHADOW_SIZE_M)
        FOOTPRINT(Spinarak)
        OVERWORLD(
            sPicTable_Spinarak,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Spinarak,
            gShinyOverworldPalette_Spinarak
        )
        .levelUpLearnset = sSpinarakLevelUpLearnset,
        .teachableLearnset = sSpinarakTeachableLearnset,
        .eggMoveLearnset = sSpinarakEggMoveLearnset,
        .frontPic = gMonFrontPic_SkyFrostbiteSpider,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .backPic = gMonBackPic_SkyFrostbiteSpider,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_SkyFrostbiteSpider,
        .shinyPalette = gMonShinyPalette_SkyFrostbiteSpider,
        .iconSprite = gMonIcon_SkyFrostbiteSpider,
        .iconPalIndex = 2,
    },
    [SPECIES_WOLF] =
    {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 70,
        .baseSpeed     = 70,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 127,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 128,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INTIMIDATE, ABILITY_QUICK_FEET, ABILITY_MOXIE },
    #else
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE, ABILITY_MOXIE },
    #endif
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Wolf"),
        .cryId = CRY_MIGHTYENA,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Bite"),
        .height = 10,
        .weight = 370,
        .description = COMPOUND_STRING(
            "In the wild, Mightyena live in a pack.\n"
            "They never defy their leader's orders.\n"
            "They defeat foes with perfectly\n"
            "coordinated teamwork."),
        .pokemonScale = 362,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 27),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 6, SHADOW_SIZE_L)
        FOOTPRINT(Mightyena)
        OVERWORLD(
            sPicTable_Mightyena,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mightyena,
            gShinyOverworldPalette_Mightyena
        )
        .levelUpLearnset = sMightyenaLevelUpLearnset,
        .teachableLearnset = sMightyenaTeachableLearnset,
        .frontPic = gMonFrontPic_SkyWolf,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .backPic = gMonBackPic_SkyWolf,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_SkyWolf,
        .shinyPalette = gMonShinyPalette_SkyWolf,
        .iconSprite = gMonIcon_SkyWolf,
        .iconPalIndex = 2,
    },
    [SPECIES_BEAR] =
    {
        .baseHP        = 60,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 66 : 124,
        .evYield_Attack = 1,
        .itemRare = ITEM_HONEY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_PICKUP, ABILITY_QUICK_FEET, ABILITY_HONEY_GATHER },
    #else
        .abilities = { ABILITY_PICKUP, ABILITY_NONE, ABILITY_HONEY_GATHER },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Bear"),
        .cryId = CRY_TEDDIURSA,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Little Bear"),
        .height = 6,
        .weight = 88,
        .description = COMPOUND_STRING(
            "It licks its palms that are sweetened by\n"
            "being soaked in honey. A Teddiursa makes\n"
            "its own honey by blending fruits and pollen\n"
            "collected by Beedrill."),
        .pokemonScale = 455,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-2, 1, SHADOW_SIZE_S)
        FOOTPRINT(Teddiursa)
        OVERWORLD(
            sPicTable_Teddiursa,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Teddiursa,
            gShinyOverworldPalette_Teddiursa
        )
        .levelUpLearnset = sTeddiursaLevelUpLearnset,
        .teachableLearnset = sTeddiursaTeachableLearnset,
        .eggMoveLearnset = sTeddiursaEggMoveLearnset,
        .frontPic = gMonFrontPic_SkyBear,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .backPic = gMonBackPic_SkyBear,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_SkyBear,
        .shinyPalette = gMonShinyPalette_SkyBear,
        .iconSprite = gMonIcon_SkyBear,
        .iconPalIndex = 2,
    },
    [SPECIES_BANDIT] =
    {
        .baseHP        = 70,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 35,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 180,
    #if P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 61,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 75,
    #else
        .expYield = 88,
    #endif
        .evYield_Attack = 1,
        .itemRare = ITEM_FOCUS_BAND,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_GUTS, ABILITY_NO_GUARD, ABILITY_STEADFAST },
    #else
        .abilities = { ABILITY_GUTS, ABILITY_NONE, ABILITY_STEADFAST },
    #endif
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Bandit"),
        .cryId = CRY_MACHOP,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Superpower"),
        .height = 8,
        .weight = 195,
        .description = COMPOUND_STRING(
            "It continually undertakes strenuous\n"
            "training to master all forms of martial\n"
            "arts. Its strength lets it easily hoist\n"
            "a sumo wrestler onto its shoulders."),
        .pokemonScale = 342,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SQUISH_AND_BOUNCE : ANIM_V_STRETCH,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 3, SHADOW_SIZE_S)
        FOOTPRINT(Machop)
        OVERWORLD(
            sPicTable_Machop,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Machop,
            gShinyOverworldPalette_Machop
        )
        .levelUpLearnset = sMachopLevelUpLearnset,
        .teachableLearnset = sMachopTeachableLearnset,
        .eggMoveLearnset = sMachopEggMoveLearnset,
        .frontPic = gMonFrontPic_SkyBandit,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .backPic = gMonBackPic_SkyBandit,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_SkyBandit,
        .shinyPalette = gMonShinyPalette_SkyBandit,
        .iconSprite = gMonIcon_SkyBandit,
        .iconPalIndex = 2,
    },
    [SPECIES_CAVE_OWL] =
    {
        .baseHP        = 100,
        .baseAttack    = 50,
        .baseDefense   = 50,
        .baseSpeed     = 70,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_7 ? 86 : 76,
        .baseSpDefense = 96,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 90,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 158,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 155,
    #else
        .expYield = 162,
    #endif
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_INSOMNIA, ABILITY_KEEN_EYE, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Cave Owl"),
        .cryId = CRY_NOCTOWL,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Owl"),
        .height = 16,
        .weight = 408,
        .description = COMPOUND_STRING(
            "It unfailingly catches prey in darkness.\n"
            "Noctowl owe their success to superior\n"
            "vision that allows them to see in minimal\n"
            "light, and to their supple and silent wings."),
        .pokemonScale = 278,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 10, SHADOW_SIZE_S)
        FOOTPRINT(Noctowl)
        OVERWORLD(
            sPicTable_Noctowl,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Noctowl,
            gShinyOverworldPalette_Noctowl
        )
        .levelUpLearnset = sNoctowlLevelUpLearnset,
        .teachableLearnset = sNoctowlTeachableLearnset,
        .frontPic = gMonFrontPic_SkyCaveOwl,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .backPic = gMonBackPic_SkyCaveOwl,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_SkyCaveOwl,
        .shinyPalette = gMonShinyPalette_SkyCaveOwl,
        .iconSprite = gMonIcon_SkyCaveOwl,
        .iconPalIndex = 0,
    },
    [SPECIES_TROLL] =
    {
        .baseHP        = 150,
        .baseAttack    = 160,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 95,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 285,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 252,
    #else
        .expYield = 210,
    #endif
        .evYield_HP = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_TRUANT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Troll"),
        .cryId = CRY_SLAKING,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Lazy"),
        .height = 20,
        .weight = 1305,
        .description = COMPOUND_STRING(
            "Hordes of Slaking gather around trees\n"
            "when fruits come into season. They wait\n"
            "around patiently for ripened fruits to fall\n"
            "out of the trees."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 300,
        .trainerOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 6, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Slaking)
        OVERWORLD(
            sPicTable_Slaking,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Slaking,
            gShinyOverworldPalette_Slaking
        )
        .levelUpLearnset = sSlakingLevelUpLearnset,
        .teachableLearnset = sSlakingTeachableLearnset,
        .frontPic = gMonFrontPic_SkyTroll,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .backPic = gMonBackPic_SkyTroll,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_SkyTroll,
        .shinyPalette = gMonShinyPalette_SkyTroll,
        .iconSprite = gMonIcon_SkyTroll,
        .iconPalIndex = 0,
    },
    [SPECIES_CROWHAG] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 42,
        .baseSpeed     = 91,
        .baseSpAttack  = 85,
        .baseSpDefense = 42,
        .types = MON_TYPES(TYPE_DARK, TYPE_FLYING),
        .catchRate = 30,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 81 : 107,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INSOMNIA, ABILITY_SUPER_LUCK, ABILITY_PRANKSTER },
    #else
        .abilities = { ABILITY_INSOMNIA, ABILITY_NONE, ABILITY_PRANKSTER },
    #endif
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Crowhag"),
        .cryId = CRY_MURKROW,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Darkness"),
        .height = 5,
        .weight = 21,
        .description = COMPOUND_STRING(
            "Murkrow were feared as the alleged\n"
            "bearers of ill fortune. It shows strong\n"
            "interest in anything that sparkles. It will\n"
            "even try to steal rings from women."),
        .pokemonScale = 401,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 0 : 12,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 8, SHADOW_SIZE_S)
        FOOTPRINT(Murkrow)
        OVERWORLD(
            sPicTable_Murkrow,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Murkrow,
            gShinyOverworldPalette_Murkrow
        )
        OVERWORLD_FEMALE(
            sPicTable_MurkrowF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sMurkrowLevelUpLearnset,
        .teachableLearnset = sMurkrowTeachableLearnset,
        .eggMoveLearnset = sMurkrowEggMoveLearnset,
    #if P_GEN_4_CROSS_EVOS
    #endif
        .frontPic = gMonFrontPic_SkyCrowhag,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .backPic = gMonBackPic_SkyCrowhag,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_SkyCrowhag,
        .shinyPalette = gMonShinyPalette_SkyCrowhag,
        .iconSprite = gMonIcon_SkyCrowhag,
        .iconPalIndex = 2,
    },
    [SPECIES_GIANT] =
    {
        .baseHP        = 144,
        .baseAttack    = 120,
        .baseDefense   = 60,
        .baseSpeed     = 50,
        .baseSpAttack  = 40,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 200,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 166 : 184,
        .evYield_HP = 2,
        .itemRare = ITEM_KINGS_ROCK,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_THICK_FAT, ABILITY_GUTS, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Giant"),
        .cryId = CRY_HARIYAMA,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Arm Thrust"),
        .height = 23,
        .weight = 2538,
        .description = COMPOUND_STRING(
            "It has the habit of challenging others\n"
            "without hesitation to tests of strength.\n"
            "It's been known to stand on train tracks\n"
            "and stop trains using forearm thrusts."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 343,
        .trainerOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_ROTATE_UP_TO_SIDES,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 9, SHADOW_SIZE_L)
        FOOTPRINT(Hariyama)
        OVERWORLD(
            sPicTable_Hariyama,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Hariyama,
            gShinyOverworldPalette_Hariyama
        )
        .levelUpLearnset = sHariyamaLevelUpLearnset,
        .teachableLearnset = sHariyamaTeachableLearnset,
        .frontPic = gMonFrontPic_SkyGiant,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .backPic = gMonBackPic_SkyGiant,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_SkyGiant,
        .shinyPalette = gMonShinyPalette_SkyGiant,
        .iconSprite = gMonIcon_SkyGiant,
        .iconPalIndex = 2,
    },
    [SPECIES_ELDER_DRAGON] =
    {
        .baseHP        = 95,
        .baseAttack    = 135,
        .baseDefense   = 80,
        .baseSpeed     = 100,
        .baseSpAttack  = 110,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_FLYING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 218,
    #endif
        .evYield_Attack = 3,
        .itemRare = ITEM_DRAGON_FANG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE, ABILITY_MOXIE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Elder Dragon"),
        .cryId = CRY_SALAMENCE,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Dragon"),
        .height = 15,
        .weight = 1026,
        .description = COMPOUND_STRING(
            "After many long years, its cellular\n"
            "structure underwent a sudden mutation to\n"
            "grow wings. When angered, it loses all\n"
            "thought and rampages out of control."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .frontAnimDelay = 70,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 8, SHADOW_SIZE_L)
        FOOTPRINT(Salamence)
        OVERWORLD(
            sPicTable_Salamence,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Salamence,
            gShinyOverworldPalette_Salamence
        )
        .levelUpLearnset = sSalamenceLevelUpLearnset,
        .teachableLearnset = sSalamenceTeachableLearnset,
        .frontPic = gMonFrontPic_SkyElderDragon,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .backPic = gMonBackPic_SkyElderDragon,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_SkyElderDragon,
        .shinyPalette = gMonShinyPalette_SkyElderDragon,
        .iconSprite = gMonIcon_SkyElderDragon,
        .iconPalIndex = 2,
    },
    [SPECIES_ANCIENT_WYRM] =
    {
        .baseHP        = 105,
        .baseAttack    = 150,
        .baseDefense   = 90,
        .baseSpeed     = 95,
        .baseSpAttack  = 150,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_FLYING),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_Attack = 2,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_AIR_LOCK, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Ancient Wyrm"),
        .cryId = CRY_RAYQUAZA,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Sky High"),
        .height = 70,
        .weight = 2065,
        .description = COMPOUND_STRING(
            "A Pokémon that flies endlessly in the\n"
            "ozone layer. It is said it would descend\n"
            "to the ground if Kyogre and Groudon\n"
            "were to fight."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 448,
        .trainerOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .frontAnimDelay = 60,
        .enemyMonElevation = 6,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 17, SHADOW_SIZE_L)
        FOOTPRINT(Rayquaza)
        OVERWORLD(
            sPicTable_Rayquaza,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Rayquaza,
            gShinyOverworldPalette_Rayquaza
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sRayquazaLevelUpLearnset,
        .teachableLearnset = sRayquazaTeachableLearnset,
        .frontPic = gMonFrontPic_SkyAncientWyrm,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .backPic = gMonBackPic_SkyAncientWyrm,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_SkyAncientWyrm,
        .shinyPalette = gMonShinyPalette_SkyAncientWyrm,
        .iconSprite = gMonIcon_SkyAncientWyrm,
        .iconPalIndex = 2,
    },
    [SPECIES_WRAITH_PRIEST] =
    {
        .baseHP        = 64,
        .baseAttack    = 115,
        .baseDefense   = 65,
        .baseSpeed     = 65,
        .baseSpAttack  = 83,
        .baseSpDefense = 63,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 159 : 179,
        .evYield_Attack = 2,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INSOMNIA, ABILITY_FRISK, ABILITY_CURSED_BODY },
    #else
        .abilities = { ABILITY_INSOMNIA, ABILITY_NONE, ABILITY_CURSED_BODY },
    #endif
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = TRUE,
        .speciesName = _("Wraith Priest"),
        .cryId = CRY_BANETTE,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Marionette"),
        .height = 11,
        .weight = 125,
        .description = COMPOUND_STRING(
            "An abandoned plush doll became this\n"
            "Pokémon. They are said to live in garbage\n"
            "dumps and wander about in search of the\n"
            "children that threw them away."),
        .pokemonScale = 262,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONVEX : ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 0,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_S)
        FOOTPRINT(Banette)
        OVERWORLD(
            sPicTable_Banette,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Banette,
            gShinyOverworldPalette_Banette
        )
        .levelUpLearnset = sBanetteLevelUpLearnset,
        .teachableLearnset = sBanetteTeachableLearnset,
        .frontPic = gMonFrontPic_SkyWraithPriest,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .backPic = gMonBackPic_SkyWraithPriest,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_SkyWraithPriest,
        .shinyPalette = gMonShinyPalette_SkyWraithPriest,
        .iconSprite = gMonIcon_SkyWraithPriest,
        .iconPalIndex = 2,
    },
    [SPECIES_BARROW_LORD] =
    {
        .baseHP        = 40,
        .baseAttack    = 70,
        .baseDefense   = 130,
        .baseSpeed     = 25,
        .baseSpAttack  = 60,
        .baseSpDefense = 130,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 159 : 179,
        .evYield_Defense = 1,
        .evYield_SpDefense = (P_UPDATED_EVS >= GEN_4) ? 1 : 2,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_FRISK },
    #else
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_NONE },
    #endif
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Barrow Lord"),
        .cryId = CRY_DUSCLOPS,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Beckon"),
        .height = 16,
        .weight = 306,
        .description = COMPOUND_STRING(
            "It is thought that its body is hollow with\n"
            "only a spectral ball of fire burning inside.\n"
            "However, no one has been able to\n"
            "confirm this theory as fact."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 299,
        .trainerOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .frontAnimDelay = 30,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 8, SHADOW_SIZE_M)
        FOOTPRINT(Dusclops)
        OVERWORLD(
            sPicTable_Dusclops,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dusclops,
            gShinyOverworldPalette_Dusclops
        )
        .levelUpLearnset = sDusclopsLevelUpLearnset,
        .teachableLearnset = sDusclopsTeachableLearnset,
    #if P_GEN_4_CROSS_EVOS
    #endif
        .frontPic = gMonFrontPic_SkyBarrowLord,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .backPic = gMonBackPic_SkyBarrowLord,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_SkyBarrowLord,
        .shinyPalette = gMonShinyPalette_SkyBarrowLord,
        .iconSprite = gMonIcon_SkyBarrowLord,
        .iconPalIndex = 2,
    },
