/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4FDC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 vx, vy, vz, pad; } Vec16_801A4FDC;
typedef struct { s32 vx, vy, vz, pad; } Vec32_801A4FDC;
extern int func_8005C49C(void);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern u8 * func_801290DC(s32 a0, u8 *a1);
extern void func_80048B6C(void *in, void *out);

void func_801A4FDC(void)
{
    Vec16_801A4FDC vec0;
    Vec32_801A4FDC vec1;
    s32 flag;
    s32 p;

    vec0.vx = (func_8005C49C() & 0xFF) - 0x80;
    vec0.vy = 0;
    vec0.vz = -(func_8005C49C() & 0x7F);

    func_8004945C((s32)&vec0, (s32)&vec0, &flag);

    vec0.vy = -0x200;
    p = (s32)func_801290DC(0x22, (u8 *)&vec0);
    if (p != 0) {
        *(u16 *)(*(s32 *)(p + 0x20) + 0x2C) = 0xC020;
        vec1.vx = 0;
        vec1.vy = -0x40000;
        vec1.vz = -(((func_8005C49C() & 0xF) + 0x1C) << 16);
        func_80048B6C(&vec1, (void *)(p + 0x10));
        *(s16 *)(p + 0x34) = 0x3000;
    }
}
