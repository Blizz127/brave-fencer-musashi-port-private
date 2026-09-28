/* Main-exec range [80018094,80018194) from the SLUS executable.
 * SHA256(span)=71f6173fe63ac65906671fe5f0b56ce7c799199153af963059b76599a72d9015.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80018094 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 a; s32 b[4]; } OtBlk_80016450;
extern void *func_80010A08(s32);
extern s32 func_80058C6C(s32, void *);
extern s32 func_80058B40(s32, s32, s32, s32);
extern s32 func_8005A600(s32, s32, s32, s32, s32);
extern u16 D_800B9A02;

void func_80018094(void *a0, s32 a1, u32 a2_p) {
    s32 a2 = (s32)a2_p;
    extern OtBlk_80016450 D_800A651C[];
    void *p2;
    s32 sz;
    s32 tp;

    sz = a1;
    if ((u32)sz >= 0x1000) {
        sz = 0xFFF;
    }

    func_80058C6C(D_800A651C[D_800B9A02].a + sz * 4, a0);

    if (a2 & 0x40000000) {
        *(u8 *)((u8 *)a0 + 7) = *(u8 *)((u8 *)a0 + 7) | 2;
        p2 = func_80010A08(0xC);
        tp = func_80058B40(2, ((u32)a2 >> 28) & 3, 0x280, 0);
        func_8005A600((s32)p2, 0, 0, (u16)tp, 0);
        func_80058C6C(D_800A651C[D_800B9A02].a + sz * 4, p2);
    }
}
