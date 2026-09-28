/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F033C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801F6CAC;
extern s32 D_801F6CA8;

void func_801F033C(void *a0) {
    register s32 a __asm__("$3");
    s32 b;

    a = D_801F6CA8;
    *(s16 *)((s32)a0 + 0xFC) = 1;
    b = D_801F6CAC;
    *(s16 *)(a + 0xFC) = 3;
    *(s16 *)(b + 0xFC) = 3;
}
