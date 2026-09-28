/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1ACC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A828(s32 a0, void *a1);
extern s32  func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern u8   D_801A64C4[];

void func_801A1ACC(s32 arg0) {
    *(s16 *)(arg0 + 0x02) = 0x14;
    *(u16 *)(arg0 + 0x34) = 0;
    *(s32 *)(arg0 + 0x1C) = 0;
    *(s32 *)(arg0 + 0xE4) = 0x20;
    func_8012A828(arg0, D_801A64C4);
    *(s32 *)(arg0 + 0xD8) = func_8012C658(0x34C, 1, arg0);
}
