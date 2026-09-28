/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A13A0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A28AC();
extern s32 func_8012BA10(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern u8 D_801F1898[];
extern u8 D_801F1978[];
extern s16 D_801F435C;
extern void func_8002D4C8(s32 a0, s32 a1);

void func_801A13A0(s32 arg0) {
    s32 s0 = arg0;

    func_801A28AC(s0);
    *(s16 *)(s0 + 2) = 0x10;
    *(s16 *)(s0 + 0x34) = 0;
    *(s32 *)(s0 + 0xE4) = 0x50;
    if (func_8012BA10(s0, 1) < 0) {
        func_8012A828(s0, D_801F1898);
        D_801F435C = 1;
    } else {
        func_8012A828(s0, D_801F1978);
        D_801F435C = -1;
    }
    *(s32 *)(s0 + 0xE0) |= 2;
    func_8002D4C8(0xB56, 0);
}
