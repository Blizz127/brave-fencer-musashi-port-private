/* Exact retail word export for [8002EA10,8002EAB0); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002EA10 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u16 D_800A4E8E;
extern s16 D_800A4E86;

extern s32  func_8003836C(s32 a0);
extern s32  func_800381E4(s32 a0, s32 a1);
extern void func_8002EC10(void);
extern void func_800383A4(s16 a0);

void func_8002EA10(void) {
    register u16 *s0 __asm__("$16");
    u16 v0;
    s32 ret;

    s0 = &D_800A4E8E;
    v0 = *s0;
    if (v0 & 4) {
        ret = func_8003836C(D_800A4E86);
        if ((ret << 16) != 0) {
            if (func_800381E4(D_800A4E86, 0) != 0) {
                func_8002EC10();
            } else {
                func_800383A4(D_800A4E86);
                *s0 = *s0 | 0x10;
            }
        }
    }
}
