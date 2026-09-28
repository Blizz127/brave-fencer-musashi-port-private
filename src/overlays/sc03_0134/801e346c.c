/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E346C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801E9E38;
extern s32 D_801E9E3C;

void func_801E346C(s32 a0_) {

    extern s32 D_801E9E38;
    extern s32 D_801E9E3C;

    register s32 c __asm__("$3") = 2;
    register s32 a0 __asm__("$4") = a0_;
    s32 p1 = D_801E9E38;

    *(s16 *)((s32)a0 + 0xFC) = 0;
    a0 = D_801E9E3C;
    *(s16 *)(p1 + 0xFC) = c;
    *(s16 *)((s32)a0 + 0xFC) = 0;
}
