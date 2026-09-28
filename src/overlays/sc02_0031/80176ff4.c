/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80176FF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u32 func_801783D0(s32 a0, s32 a1);
extern void func_801778A8(int param_1, unsigned int param_2, short param_3, short param_4);
extern u16 D_8011F82C;
extern u16 D_8011F82A;

void func_80176FF4(s32 a0) {
    s32 v0;
    a0 += 0x50;
    func_801778A8(a0, (s16)func_801783D0(D_8011F82C, 4), 3, 0xFF);
    a0 += 0x3C;
    func_801778A8(a0, (s16)func_801783D0(D_8011F82A, 4), 3, 0xFF);
    a0 += 0x3C;
    *(s16 *)(a0 + 0xC) = (u32)(D_8011F82C * 10355) >> 15;
    a0 += 0x14;
    v0 = ((s32)(D_8011F82A * 10355) << 1) >> 16;
    *(s16 *)(a0 + 0xC) = v0;
    *(s16 *)(a0 + 0x20) = v0 + 2;
}
