/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A61C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012BDBC(s32 a0, s32 a1);
extern s32 func_8012BA10(s32 a0, s32 a1);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);

void func_801A61C4(s32 arg0) {
    if (func_8012BDBC(arg0, 0x280) != 0) {
        *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x12) += func_8012BA10(arg0, 8);
    } else {
        *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x12) += func_8012B608(
            *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12),
            *(s16 *)(*(s32 *)(*(s32 *)(arg0 + 0x64) + 0x20) + 0x12),
            8);
    }
}
