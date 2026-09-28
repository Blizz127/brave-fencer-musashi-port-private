/* Exact retail word export for [8002EAB0,8002EB10); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002EAB0 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u16   D_800A4E8E;
extern s16   D_800A4E86;
extern void func_80038308(s16 a0);

void func_8002EAB0(void) {
    register u16 *s0 __asm__("$16");
    u16 v0;

    s0 = &D_800A4E8E;
    v0 = *s0;
    if ((v0 & 0x10) != 0) {
        func_80038308(D_800A4E86);
        v0 = *s0;
        v0 = (v0 | 0x9) & 0xFFEF;
        *s0 = v0;
    }
}
