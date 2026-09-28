/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A09E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A4328(s32 a0);
extern void func_8017F880(void);
extern void func_801A34C4(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
extern void func_8012AD44(s32 *a0, s16 a1);
extern s32 D_801EF088;
extern u16 D_8019FF8A;

void func_801A09E4(s32 a0) {
    s32 v1;
    s32 v0;
    s32 v2;

    func_801A4328(3);
    func_8017F880();
    func_801A34C4(a0);
    func_8012A828(a0, &D_801EF088);
    *(s32 *)(a0 + 0xCC) = func_8012C658(0x32A, 0, a0);

    v1 = *(volatile s32 *)(a0 + 0xCC);
    D_8019FF8A &= 0xFEFF;
    if (v1 != 0) {
        D_8019FF8A |= 2;
    }

    v0 = D_8019FF8A | 0x80;
    v2 = *(u16 *)(a0 + 0x5C) & 0xDFFF;
    D_8019FF8A = v0;
    *(u16 *)(a0 + 0x5C) = v2;
    func_8012AD44((s32 *)a0, 3);
}
