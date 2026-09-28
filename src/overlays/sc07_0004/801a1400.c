/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1400 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A4328(s32 a0);
extern void func_8017F928(void);
extern void func_801A36F0(void *a0);
extern void func_801A34C4(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012AD44(s32 *a0, s16 a1);
extern s32 D_801EF8A0;

void func_801A1400(s32 *a0)
{
    s32 *s0 = a0;
    u16 v0;

    func_801A4328(4);
    func_8017F928();
    func_801A36F0(s0);
    *(u16 *)((s32)s0 + 0x102) = 0;
    func_801A34C4((s32)s0);
    v0 = *(u16 *)((s32)s0 + 0x5C);
    *(u16 *)((s32)s0 + 0x5C) = v0 & 0xDFFF;
    func_8012A828((s32)s0, &D_801EF8A0);
    func_8012AD44(s0, 7);
}
