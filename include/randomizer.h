#ifndef GUARD_RANDOMIZER_H
#define GUARD_RANDOMIZER_H

void RandomizerInit(void);
enum Species RandomizeWildSpecies(enum Species species);
enum Species RandomizeStarterSpecies(enum Species species, u32 slot);

#endif // GUARD_RANDOMIZER_H
