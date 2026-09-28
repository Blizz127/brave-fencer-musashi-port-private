/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5AE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *a0, u16 a1);
extern u8 D_801F4444[];
extern u8 D_801F4448[];
typedef struct { u8 d[4]; } Blk4;
extern const Blk4 D_801A01CC ;  /* data at its retail address */
extern const Blk4 D_801A01D0 ;  /* data at its retail address */

void func_801A5AE0(void *a0) {
    void *s1 = D_801F4444;

    func_8001CD50(*(s32 *)((s32)a0 + 0x20), (s32)s1);

    *(u16 *)((s32)a0 + 0xA) -= 0x100;
    *(s32 *)(*(s32 *)((s32)a0 + 0x20) + 0x4) |= 0x50000000;
    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x10) = 0x400;

    *(u16 *)((s32)a0 + 0x2C) = 0x10;
    func_800233CC(s1, 0x10);

    *(Blk4 *)s1 = D_801A01CC;
    *(Blk4 *)D_801F4448 = D_801A01D0;

    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1E) = 0xC00;
    *(u16 *)((s32)a0 + 0x2) += 1;
}
