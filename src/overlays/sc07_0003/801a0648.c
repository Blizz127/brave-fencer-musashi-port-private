/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A0648 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012BEE8(s32 a0);
extern void func_8012BD14(s32);

void func_801A0648(s32 arg0) {
    if (func_8012BEE8(arg0) != 0) {
        *(s16 *)(arg0 + 2) = 7;
    }
    if (*(s32 *)(arg0 + 0x1C) < 0x20) {
        if (((s32 (*)(s32))func_8012BD14)(arg0) <= 0x10000) {
            *(s16 *)(arg0 + 2) = 0xF;
        }
    }
}
