/* Exact retail word export for [8003916C,800391D4); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8003916C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

void func_8003916C(s16 arg0)
{
    extern u8 D_800C6DD0[];
    u8 *a1;
    s32 off;

    a1 = &D_800C6DD0[arg0 * 0x60];
    if (a1[0x5A] != 0) {
        off = *(s16 *)&a1[6] * 26;
        *(u8 *)(*(u32 *)&a1[0x50] + off + arg0 + 0x23) = 0;
        a1[0x5A] = 0;
    }
}
