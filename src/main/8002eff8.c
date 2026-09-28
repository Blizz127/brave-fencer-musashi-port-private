/* Exact retail word export for [8002EFF8,8002F064); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002EFF8 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 D_800A2B98;
extern s32 D_800C7D20;

void func_8002EFF8(s32 a0, s32 a1)
{
    register s32 v0 __asm__("$2");
    register s32 v1 __asm__("$3");
    register s32 a0_tmp __asm__("$4");

    v0 = 1;

    if (a0 == v0) {
        v0 = ~a1;
        v1 = D_800A2B98;
        a0_tmp = D_800C7D20;
        v1 = v1 & v0;
        a0_tmp = a0_tmp | a1;
        D_800A2B98 = v1;
        D_800C7D20 = a0_tmp;
    } else {
        v0 = ~a1;
        v1 = D_800C7D20;
        a0_tmp = D_800A2B98;
        v1 = v1 & v0;
        a0_tmp = a0_tmp | a1;
        D_800C7D20 = v1;
        D_800A2B98 = a0_tmp;
    }
}
