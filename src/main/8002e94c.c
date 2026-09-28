/* Exact retail word export for [8002E94C,8002EA10); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002E94C - byte-exact against retail at -O2 (tools/register_match.py). */

void func_8002E94C(s32 a0)
{
    extern u16 D_800A4E8E;
    extern u16 D_800A4E8C;
    extern u8  D_800A4EE6;
    extern u16 D_800A4EE4;
    extern u16 D_800A4EE2;
    extern u16 D_8006A9EC[];
    extern void func_8002EAB0(void);
    register u8 *a1 __asm__("$5");
    u8 fl;
    u8 clr;
    u16 v;

    if ((D_800A4E8E & 0x4) != 0 && D_800A4E8C == 0x3E && (D_800A4E8E & 0x10) != 0) {
        func_8002EAB0();
    }

    a1 = &D_800A4EE6;
    fl = *a1;
    if (fl & 0x4) {
        clr = fl & 0xFB;
        *a1 = clr;
        if (!(fl & 0x2)) {
            if ((u16)a0 >= 5) {
                a0 = 4;
            }
            D_800A4EE4 = 0x4000;
            v = D_8006A9EC[(u16)a0];
            *a1 = clr | 0x1;
            D_800A4EE2 = v;
        }
    }
}
