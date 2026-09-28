/* Exact retail word export for [8002E79C,8002E818); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002E79C - byte-exact against retail at -O2 (tools/register_match.py). */

void func_8002E79C(s32 a0)
{
    extern u8  D_800A4EE6;
    extern u16 D_800A4EE0;
    extern u16 D_800A4EE2;
    extern u16 D_800A4EE4;
    extern u16 D_8006A9C8[];
    u8 *fl;
    u16 v;

    fl = &D_800A4EE6;
    if (!(*fl & 2)) {
        *fl |= 2;
        if (!(*fl & 4)) {
            v = (u16)a0;
            if (v >= 5) {
                v = 4;
            }
            D_800A4EE0 = 0x4000;
            D_800A4EE4 = 0x2FFF;
            D_800A4EE2 = D_8006A9C8[v];
            *fl |= 3;
        }
    }
}
