/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801395D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
} Stk801395D4;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80059888(void *a0, s32 a1, s32 a2, s32 a3);

void func_801395D4(void * a0)
{
    Stk801395D4 sp10;
    u16 mul;
    u16 base;
    sp10.f0 = *(u16 *)(a0 + 0x38);
    mul = *(u16 *)(a0 + 0x12);
    base = *(u16 *)(a0 + 0x3A);
    sp10.f4 = 0x38;
    sp10.f6 = 0xC;
    sp10.f2 = base + mul * 12;
    func_80059888(&sp10, 0, 0, 0);
}
