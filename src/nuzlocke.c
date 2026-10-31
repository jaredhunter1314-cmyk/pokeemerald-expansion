#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "item.h"
#include "main.h"
#include "nuzlocke.h"
#include "overworld.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "string_util.h"
#include "constants/battle.h"
#include "constants/flags.h"
#include "constants/items.h"

// Hardcore Nuzlocke rules. Active when FLAG_HARDCORE_NUZLOCKE is set.
// The "areas already encountered" bitset is stored in 16 otherwise unused script vars (256 bits).
static const u16 sEncounterVars[16] =
{
    VAR_UNUSED_0x408B,
    VAR_UNUSED_0x4091,
    VAR_UNUSED_0x409B,
    VAR_UNUSED_0x409D,
    VAR_UNUSED_0x40A1,
    VAR_UNUSED_0x40A8,
    VAR_UNUSED_0x40B8,
    VAR_UNUSED_0x40BB,
    VAR_UNUSED_0x40DB,
    VAR_UNUSED_0x40DC,
    VAR_UNUSED_0x40E5,
    VAR_UNUSED_0x40F7,
    VAR_UNUSED_0x40F8,
    VAR_UNUSED_0x40F9,
    VAR_UNUSED_0x40FA,
    VAR_UNUSED_0x40FB,
};

#define DEAD_BOX (TOTAL_BOXES_COUNT - 1)

static bool8 sCanCatch = TRUE;

bool8 Nuzlocke_IsActive(void)
{
    return FlagGet(FLAG_HARDCORE_NUZLOCKE);
}

bool8 Nuzlocke_CanCatch(void)
{
    return sCanCatch;
}

// Called whenever a wild Pokemon is generated: only the first one met in each area can be caught.
void Nuzlocke_RegisterWildEncounter(void)
{
    u8 area;
    u16 var, bit;

    if (!Nuzlocke_IsActive())
        return;

    area = GetCurrentRegionMapSectionId();
    var = sEncounterVars[area >> 4];
    bit = 1 << (area & 15);

    if (VarGet(var) & bit)
    {
        sCanCatch = FALSE;
    }
    else
    {
        VarSet(var, VarGet(var) | bit);
        sCanCatch = TRUE;
    }
}

// No battle items, except Poke Balls.
bool8 Nuzlocke_BlocksItem(u16 item)
{
    if (!Nuzlocke_IsActive())
        return FALSE;
    return GetItemPocket(item) != POCKET_POKE_BALLS;
}

static void NameDeadBox(void)
{
    StringCopy(GetBoxNamePtr(DEAD_BOX), COMPOUND_STRING("DEAD"));
}

static u32 CountLivingPartyMons(void)
{
    u32 i, living = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) != SPECIES_NONE
         && !GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_IS_EGG)
         && GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_HP) != 0)
            living++;
    }
    return living;
}

// Permadeath: fainted Pokemon are moved to the DEAD box after the battle.
void Nuzlocke_AfterBattle(void)
{
    u32 i, pos;

    sCanCatch = TRUE;
    if (!Nuzlocke_IsActive())
        return;

    NameDeadBox();

    if (gBattleOutcome == B_OUTCOME_LOST || CountLivingPartyMons() == 0)
        return;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];

        if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE
         || GetMonData(mon, MON_DATA_IS_EGG)
         || GetMonData(mon, MON_DATA_HP) != 0)
            continue;

        for (pos = 0; pos < IN_BOX_COUNT; pos++)
        {
            if (GetBoxMonDataAt(DEAD_BOX, pos, MON_DATA_SPECIES) == SPECIES_NONE)
            {
                SetBoxMonAt(DEAD_BOX, pos, &mon->box);
                ZeroMonData(mon);
                break;
            }
        }
    }
    CompactPartySlots();
    CalculatePlayerPartyCount();
}

// Party wipe = game over: reset to the title screen (progress since the last save is lost).
void Nuzlocke_OnWhiteout(void)
{
    if (Nuzlocke_IsActive())
        DoSoftReset();
}
