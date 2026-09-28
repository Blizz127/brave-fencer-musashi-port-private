/* Exact retail word export for [8002E818,8002E8DC); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002E818 - byte-exact against retail at -O2 (tools/register_match.py). */

void func_8002E818(s32 a0)
{
    extern u16 D_800A4E8E;
    extern u16 D_800A4E8C;
    extern u8  D_800A4EE6;
    extern u16 D_800A4EE0;
    extern u16 D_800A4EE2;
    extern u16 D_800A4EE4;
    extern u16 D_8006A9D4[];
    extern void func_8002EA10(void);
    register u8 *a1 __asm__("$5");
    u8 fl;
    u8 nw;
    u16 v;

    if ((D_800A4E8E & 0x4) != 0 && D_800A4E8C == 0x3E) {
        func_8002EA10();
    }

    a1 = &D_800A4EE6;
    fl = *a1;
    if (!(fl & 4)) {
        nw = fl | 4;
        *a1 = nw;
        if (!(nw & 2)) {
            if ((u16)a0 >= 5) {
                a0 = 4;
            }
            D_800A4EE0 = 0x4000;
            D_800A4EE4 = 0x2000;
            v = D_8006A9D4[(u16)a0];
            *a1 = fl | 5;
            D_800A4EE2 = v;
        }
    }
}
