#include "global.h"
#include "event_data.h"
#include "main.h"
#include "pokemon.h"
#include "random.h"
#include "randomizer.h"
#include "constants/species.h"

// The seed lives in two otherwise unused script vars, so it is stored in the save file.
#define VAR_RANDOMIZER_SEED_LO VAR_UNUSED_0x404E
#define VAR_RANDOMIZER_SEED_HI VAR_UNUSED_0x4083

static u32 GetSeed(void)
{
    return ((u32)VarGet(VAR_RANDOMIZER_SEED_HI) << 16) | VarGet(VAR_RANDOMIZER_SEED_LO);
}

void RandomizerInit(void)
{
    u32 seed = Random32() ^ ((u32)gSaveBlock2Ptr->playerTrainerId[0] << 24)
                          ^ ((u32)gSaveBlock2Ptr->playerTrainerId[1] << 16)
                          ^ ((u32)gSaveBlock2Ptr->playerTrainerId[2] << 8)
                          ^ gSaveBlock2Ptr->playerTrainerId[3]
                          ^ (gMain.vblankCounter1 * 2654435761u);
    if (seed == 0)
        seed = 1;
    VarSet(VAR_RANDOMIZER_SEED_LO, seed & 0xFFFF);
    VarSet(VAR_RANDOMIZER_SEED_HI, seed >> 16);
}

static u32 Hash(u32 seed, u32 x)
{
    x ^= seed;
    x *= 0x9E3779B1u;
    x ^= x >> 15;
    x *= 0x85EBCA77u;
    x ^= x >> 13;
    x *= 0xC2B2AE3Du;
    x ^= x >> 16;
    return x;
}

static bool8 IsUsableForm(enum Species s)
{
    if (s <= SPECIES_NONE || s >= NUM_SPECIES)
        return FALSE;
    if (!IsSpeciesEnabled(s))
        return FALSE;
    if (gSpeciesInfo[s].isMegaEvolution || gSpeciesInfo[s].isPrimalReversion
     || gSpeciesInfo[s].isUltraBurst || gSpeciesInfo[s].isGigantamax
     || gSpeciesInfo[s].isTotem || gSpeciesInfo[s].isTeraForm)
        return FALSE;
    return TRUE;
}

static bool8 IsGoodStarter(enum Species s)
{
    if (!IsUsableForm(s))
        return FALSE;
    if (gSpeciesInfo[s].isRestrictedLegendary || gSpeciesInfo[s].isSubLegendary
     || gSpeciesInfo[s].isMythical || gSpeciesInfo[s].isUltraBeast || gSpeciesInfo[s].isParadox)
        return FALSE;
    if (GetSpeciesPreEvolution(s) != SPECIES_NONE) // first stage only
        return FALSE;
    if (GetSpeciesEvolutions(s) == NULL)           // must be able to evolve
        return FALSE;
    return TRUE;
}

// Same original species always maps to the same new species within one save.
enum Species RandomizeWildSpecies(enum Species species)
{
    u32 seed = GetSeed();
    u32 i;

    if (seed == 0)
        return species;
    for (i = 0; i < 200; i++)
    {
        enum Species candidate = 1 + Hash(seed, species * 977u + i) % (NUM_SPECIES - 1);
        if (IsUsableForm(candidate))
            return candidate;
    }
    return species;
}

enum Species RandomizeStarterSpecies(enum Species species, u32 slot)
{
    u32 seed = GetSeed();
    u32 i;

    if (seed == 0)
        return species;
    for (i = 0; i < 2000; i++)
    {
        enum Species candidate = 1 + Hash(seed, 0x51A7u + slot * 7919u + i) % (NUM_SPECIES - 1);
        if (IsGoodStarter(candidate))
            return candidate;
    }
    return species;
}
