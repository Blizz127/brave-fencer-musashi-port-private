/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801706AC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80181744[])(void);

void func_801706AC(void *a0) {
    D_80181744[*(u8 *)((s32)a0 + 0x216)]();
}
