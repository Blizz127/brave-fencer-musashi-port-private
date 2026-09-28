/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A3334 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012C218(void *a0);
extern void func_801A38E4(void *a0, void *a1, s32 a2, s32 a3, s32 a4);
extern void func_801A3BCC(void *a0);
extern u16 D_801F43C0;
extern u8 D_801A6DA4[4];

void func_801A3334(void *a0) {
    void *s1;      /* the actor          */
    void *s2;      /* linked actor @+0x64 */
    void *s3;      /* &s1->parts[0]  (+0xCC), strides 0x10 */
    s32 s4;        /* part-id bias: -2 when D_801F43C0 == 0x11 */
    s32 s5;
    s32 i;

    s1 = a0;
    s3 = (u8 *)s1 + 0xCC;
    s2 = *(void **)((u8 *)s1 + 0x64);
    s4 = 0;

    /* +0x00 is a u16 type tag; anything but 0x322 takes the generic path */
    if (*(u16 *)s2 != 0x322) {
        func_8012C218(a0);
        return;
    }

    if (D_801F43C0 == 0x11) {
        s4 = -2;
    }

    /* i = 0 must be the FIRST statement of the join block: reorg steals it into
       the bne's delay slot, leaving `s5 = 1` at .L801A339C (§194 delay-slot steal). */
    i = 0;
    s5 = 1;
    /* the s3 stride lives in the for-clause, AFTER i++ -- that ordering is what
       puts the a3/lbu group ahead of `a1 = s3` in sched1's arg setup. */
    for (; i < 3; i++, s3 = (u8 *)s3 + 0x10) {
        func_801A38E4(s2, s3, D_801A6DA4[i] + s4, i, s5);
    }

    /* unaligned (align-1) 8-byte copy: (*(s1+0x20))[+0x10] = (*(s2+0x20))[+0x10] */
    {
        typedef struct { u16 a, b, c, d; } Vec8;
        *(Vec8 *)((u8 *)*(u32 *)((u8 *)s1 + 0x20) + 0x10) =
            *(Vec8 *)((u8 *)*(u32 *)((u8 *)s2 + 0x20) + 0x10);
    }

    *(s32 *)((u8 *)s1 + 0x4) = *(s32 *)((u8 *)s2 + 0x4);
    *(s32 *)((u8 *)s1 + 0x8) = *(s32 *)((u8 *)s2 + 0x8);
    *(s32 *)((u8 *)s1 + 0xC) = *(s32 *)((u8 *)s2 + 0xC);

    if (*(s32 *)((u8 *)s2 + 0xE0) & 0x2) {
        *(u16 *)((u8 *)s1 + 0x5C) = *(u16 *)((u8 *)s1 + 0x5C) & 0xF7FF;
        func_801A3BCC(s1);
    } else {
        *(u16 *)((u8 *)s1 + 0x5C) = *(u16 *)((u8 *)s1 + 0x5C) | 0x0800;
    }
}
