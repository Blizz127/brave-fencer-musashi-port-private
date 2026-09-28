/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80167A9C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80181220[])(void);

void func_80167A9C(void *a0) {
    D_80181220[*(u16 *)((s32)a0 + 0x2)]();
}
