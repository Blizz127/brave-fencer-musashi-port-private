/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F02B0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801F6CAC;
extern s32 D_801F6CA8;

void func_801F02B0(s32 a0_) {

    extern s32 D_801F6CA8;
    extern s32 D_801F6CAC;

    register s32 c __asm__("$3") = 1;
    register s32 a0 __asm__("$4") = a0_;
    s32 p1 = D_801F6CA8;

    *(s16 *)((s32)a0 + 0xFC) = 0;
    a0 = D_801F6CAC;
    *(s16 *)(p1 + 0xFC) = c;
    *(s16 *)((s32)a0 + 0xFC) = 0;
}
