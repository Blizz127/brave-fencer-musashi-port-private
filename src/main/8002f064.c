/* Exact retail word export for [8002F064,8002F0D0); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002F064 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 D_800A2BA0;
extern s32 D_800C7D2C;

void func_8002F064(s32 a0, s32 a1) {
    register s32 v0 __asm__("$2");
    register s32 v1 __asm__("$3");
    register s32 out_a0 __asm__("$4");

    if (a0 == 1) {
        v0 = ~a1;
        v1 = D_800A2BA0;
        out_a0 = D_800C7D2C;
        v1 = v1 & v0;
        out_a0 = out_a0 | a1;
        D_800A2BA0 = v1;
        D_800C7D2C = out_a0;
    } else {
        v0 = ~a1;
        v1 = D_800C7D2C;
        out_a0 = D_800A2BA0;
        v1 = v1 & v0;
        out_a0 = out_a0 | a1;
        D_800C7D2C = v1;
        D_800A2BA0 = out_a0;
    }
}
