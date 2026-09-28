/* Exact retail word export for [8002D29C,8002D320); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002D29C - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 D_800A46B4;
extern u16 D_800A46B8;
extern u16 D_800A4EF4;
extern u8 D_800A46BA;

extern int func_8003EDE8(int a0, int a1, int a2);
extern void func_8002EE90(void);

void func_8002D29C(void) {
    s32 *s1;
    s32 s0;
    s16 v0;
    s16 v1;

    s1 = &D_800A46B4;
    s0 = *s1;
    v0 = D_800A4EF4;
    func_8003EDE8(0, (s0 * v0) >> 16, (s0 * v0) >> 16);
    v1 = D_800A46B8;
    s0 -= v1;
    if (s0 <= 0) {
        D_800A46BA = 0;
        func_8002EE90();
        s0 = 0;
    }
    *s1 = s0;
}
