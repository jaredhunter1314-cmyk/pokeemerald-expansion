#ifndef GUARD_NUZLOCKE_H
#define GUARD_NUZLOCKE_H

bool8 Nuzlocke_IsActive(void);
bool8 Nuzlocke_CanCatch(void);
void Nuzlocke_RegisterWildEncounter(void);
void Nuzlocke_AfterBattle(void);
void Nuzlocke_OnWhiteout(void);
bool8 Nuzlocke_BlocksItem(u16 item);

#endif // GUARD_NUZLOCKE_H
