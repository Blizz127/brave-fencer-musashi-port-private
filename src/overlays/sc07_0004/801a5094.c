/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5094 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 vx, vy, vz, pad; } Vec16_801A5094;
typedef struct { s32 vx, vy, vz, pad; } Vec32_801A5094;
extern int func_8005C49C(void);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern u8 * func_801290DC(s32 a0, u8 *a1);
extern void func_80048B6C(void *in, void *out);
extern u8 D_801F8744[];
extern u8 D_801F8747[];

void func_801A5094(void)
{
    Vec16_801A5094 vec0;
    Vec32_801A5094 vec1;
    s32 flag;
    s32 p;
    s32 r;

    vec0.vx = (func_8005C49C() % 320) - 160;
    vec0.vy = -((func_8005C49C() & 0x7F) + 0x40);
    vec0.vz = -((func_8005C49C() & 0x3F) + 0x20);

    func_8004945C((s32)&vec0, (s32)&vec0, &flag);

    p = (s32)func_801290DC(0x2E, (u8 *)&vec0);
    if (p != 0) {
        *(u16 *)(*(s32 *)(p + 0x20) + 0x2C) = 0xC020;
        vec1.vx = 0;
        vec1.vy = 0;
        r = func_8005C49C();
        vec1.vz = -(((r & 7) + 0x20) << 16);
        func_80048B6C(&vec1, (void *)(p + 0x10));
        D_801F8747[0] = 1;
        __asm__ __volatile__("");
        *(s32 *)(p + 0x34) = *(s32 *)D_801F8744;
        *(s16 *)(p + 0x30) = 6;
    }
}
