/* Exact retail word export for [80034A54,80034A9C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80034A54 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s8 D_800A4F17;

void func_80034A54(s32 a0) {
    s32 self = a0;
    u8 v0 = *(u8 *)(self + 0x37);

    if ((v0 & 0x1) != 0) {
        s8 *p = &D_800A4F17;
        s8 old = *p;
        *p = 1;
        *(u8 *)(self + 0x32) = 1;
        *(s16 *)(self + 0x2E) = 0x3FF;
        *(s16 *)(self + 0x30) = 0xFFF;
        *p = old;
    }
}
