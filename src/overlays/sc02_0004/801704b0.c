/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801704B0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_801811C4[])(void);

void func_801704B0(void *a0) {
    D_801811C4[*(u8 *)((s32)a0 + 0x216)]();
}
