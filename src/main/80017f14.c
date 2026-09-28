/* Main-exec range [80017F14,80018094) from the SLUS executable.
 * SHA256(span)=f61162deeff4827870c8cd50076dc742ab90f132cf6cf8773d195a8c3c52a6af.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80017F14 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_800B9A02;
extern s32 func_80058B40(s32 tp, s32 abr, s32 x, s32 y);
extern void *func_80010A08(s32 a0);
extern s32 func_80058C6C(s32, void *);
extern s32 func_8005A600(s32, s32, s32, s32, s32);

void func_80017F14(void *a0, s32 a1, s32 a2)
{
    extern u16 D_800B9A02;
    extern struct { s32 a; s32 b[4]; } D_800A651C[];
    extern void *func_80010A08(s32);
    extern s32 func_80058C6C(s32, void *);
    extern s32 func_80058B40(s32, s32, s32, s32);
    extern s32 func_8005A600(s32, s32, s32, s32, s32);

    void *p2;
    s32 sz;
    s32 tp;

    /* sz clamp: >= 0x1000 saturates to 0xFFF (sltiu/bnez/addiu triple) */
    sz = a1;
    if ((u32)sz >= 0x1000) {
        sz = 0xFFF;
    }

    p2 = func_80010A08(0xC);
    tp = func_80058B40(2, ((u32)a2 >> 28) & 3, 0x280, 0);
    func_8005A600((s32)p2, 0, 0, (u16)tp, 0);
    func_80058C6C(D_800A651C[D_800B9A02].a + sz * 4, p2);

    func_80058C6C(D_800A651C[D_800B9A02].a + sz * 4, a0);

    /* guard covers ONLY the code |=2 — the second tpage packet follows
     * UNCONDITIONALLY (beqz target sits before its jal func_80010A08) */
    if ((u32)a2 & 0x40000000) {
        *(u8 *)((u8 *)a0 + 7) = *(u8 *)((u8 *)a0 + 7) | 2;
    }

    p2 = func_80010A08(0xC);
    tp = func_80058B40(2, ((u32)a2 >> 28) & 3, 0x280, 0);
    func_8005A600((s32)p2, 0, 1, (u16)tp, 0);
    func_80058C6C(D_800A651C[D_800B9A02].a + sz * 4, p2);
}
