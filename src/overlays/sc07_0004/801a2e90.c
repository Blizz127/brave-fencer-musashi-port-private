/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A2E90 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A3EEC(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_801A36F0(void *a0);
extern void func_801A34C4(s32 a0);
extern u16 D_8019FF8A;
extern u8 D_801C6614;
extern u8 D_801C6674;
extern u8 D_801EF9A8;
extern s16 D_801F8860;
extern void func_800183E0(s32 a0);

void func_801A2E90(s32 a0)
{
    s32 s0;
    u16 v0;
    u16 v1;
    s32 v2;

    s0 = a0;
    func_801A36F0((void *)s0);
    func_801A34C4(s0);
    *(s16 *)(s0 + 0xE6) = -1;
    v0 = *(u16 *)(s0 + 0x5C) & 0xFFFE;
    v1 = D_8019FF8A | 0x208;
    *(u16 *)(s0 + 0x5C) = v0;
    D_8019FF8A = v1;
    func_800183E0((s32)&D_801C6614);
    func_800183E0((s32)&D_801C6674);
    func_8012A828(s0, &D_801EF9A8);
    v2 = D_801F8860;
    *(s16 *)(s0 + 0xF8) = 0;
    if (v2 != 1) {
        func_801A3EEC(1);
    }
}
