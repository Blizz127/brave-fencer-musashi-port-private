/* Exact retail word export for [8002E8DC,8002E94C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002E8DC - byte-exact against retail at -O2 (tools/register_match.py). */

void func_8002E8DC(s32 a0)
{
    extern u8  D_800A4EE6;
    extern u16 D_800A4EE2;
    extern u16 D_800A4EE4;
    extern u16 D_8006A9E0[];
    register u8 *p __asm__("$6");
    u8 fl;
    u8 nw;
    u16 v;

    p = &D_800A4EE6;
    fl = *p;
    if (fl & 2) {
        nw = fl & 0xFD;
        *p = nw;
        if (!(fl & 4)) {
            if ((u16)a0 >= 5) {
                a0 = 4;
            }
            D_800A4EE4 = 0x4000;
            v = D_8006A9E0[(u16)a0];
            *p = nw | 1;
            D_800A4EE2 = v;
        }
    }
}
