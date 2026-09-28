/* Exact retail word export for [8002EC10,8002ED90); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002EC10 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u16 D_800A4E8E;
extern s16 D_800A4E86;
extern u16 D_800A4E8C;
extern u16 D_800A4F20;
extern u16 D_800A4F22;
extern u16 D_800A4E8A;
extern u16 D_80068B66[][8];
extern u16 D_800A4EA2;
extern s16 D_800A4E9A;
extern u16 D_800A4EA0;

extern s32 func_8003836C(s32 a0);
extern void func_800383A4(s16 a0);
extern void func_800384A8(s16 a0);
extern void func_800385C0(s16 a0);

void func_8002EC10(void) {
    u16 v0;
    s16 *s0;

    D_800A4F20 = 0;
    D_800A4F22 = 0;
    D_800A4E8A = 0;

    if (D_800A4E8E & 4) {
        if ((s16)func_8003836C(D_800A4E86) && (D_80068B66[D_800A4E8C][0] & 1)) {
            if (D_800A4EA2 & 4) {
                func_800385C0(D_800A4E9A);
                D_800A4EA2 &= 0xFEE8;
            }

            func_800383A4(D_800A4E86);

            v0 = D_800A4E8E;
            D_800A4E8E = v0 & 0xFFFD;
            D_800A4EA2 = v0 & 0xFFFD;
            D_800A4E9A = D_800A4E86;
            D_800A4EA0 = D_800A4E8C;
            D_800A4E8E = v0 & 0xFEF9;
            return;
        }

        s0 = &D_800A4E86;
        if ((s16)func_8003836C(*s0)) {
            func_800384A8(*s0);
        }

        D_800A4E8E &= 0xFEE8;
        func_800385C0(*s0);
    }
}
