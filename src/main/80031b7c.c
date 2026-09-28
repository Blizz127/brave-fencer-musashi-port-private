/* Exact retail word export for [80031B7C,80031BE0); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80031B7C - byte-exact against retail at -O2 (tools/register_match.py). */

extern void func_80031B7C(void);
extern u8 D_800A49D2[];

void func_80031B7C() {
    register s32 a0 asm("$4") = 0;
    register u8 a2 asm("$6") = 1;
    register u16 a1 asm("$5") = 0x7FFF;
    register u8 *v1 asm("$3");

    v1 = D_800A49D2;

    do {
        if (v1[4] && !v1[2] && v1[3]) {
            v1[2] = a2;
            *(u16 *)v1 = a1;
        }
        v1 += 0x54;
        a0++;
    } while (a0 < 8);
}
