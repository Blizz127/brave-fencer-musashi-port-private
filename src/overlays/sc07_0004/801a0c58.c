/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A0C58 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A36F0(void *a0);
extern void func_801A34C4(s32 a0);
extern void func_801A4328(s32 a0);
extern void func_8017F9CC(void);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8005C49C(void);
extern void func_8012AD44(s32 *a0, s16 a1);
extern s32 D_801EEB70;

void func_801A0C58(s32 *a0)
{
    s32 *s0 = a0;
    s32 v0;

    func_801A36F0(s0);
    func_801A34C4((s32)s0);
    func_801A4328(6);
    func_8017F9CC();

    v0 = *(u16 *)((s32)s0 + 0x5C);
    *(u16 *)((s32)s0 + 0x5C) = v0 & 0xDFFF;
    func_8012A828((s32)s0, &D_801EEB70);

    *(u16 *)((s32)s0 + 0x100) = 0;
    *(u16 *)((s32)s0 + 0x102) = func_8005C49C() & 3;
    func_8012AD44(s0, 4);
}
