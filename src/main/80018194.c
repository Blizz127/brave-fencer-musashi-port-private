/* Main-exec range [80018194,8001820C) from the SLUS executable.
 * SHA256(span)=3eae54476c1a0728f9d7b74f960d5ec1172ea9e20168d925f2bdf18079f1ada1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80018194 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80058C6C(s32, void *);
extern u16 D_800B9A02;

void func_80018194(void *arg0, s32 arg1, u32 arg2)
{
    extern s32 func_80058C6C(s32, void *);
    extern u16 D_800B9A02;
    extern struct { s32 a; s32 b[4]; } D_800A651C[];
    void *a3;
    s32 sz;

    a3 = arg0;
    if (arg2 & 0x40000000) {
        *(u32 *)((u8 *)a3 + 4) |= 0x02000000;
    }

    sz = arg1;
    if ((u32)sz >= 0x1000) {
        sz = 0xFFF;
    }

    func_80058C6C(D_800A651C[D_800B9A02].a + sz * 4, a3);
}
