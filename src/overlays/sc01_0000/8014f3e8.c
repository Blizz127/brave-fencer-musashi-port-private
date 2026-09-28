/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014F3E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8014F468();
extern int func_8014F6F4();

s32 func_8014F3E8(s32 param_1)
{
    if ((*(u32 *)(param_1 + 0x44) & 0x40000) == 0) {
        if ((*(s16 *)(param_1 + 6) == *(s16 *)(param_1 + 0x88)) &&
            (*(s16 *)(param_1 + 10) == *(s16 *)(param_1 + 0x8a)) &&
            (*(s16 *)(param_1 + 0xe) == *(s16 *)(param_1 + 0x8c))) {
            return ((s32 (*)(void))func_8014F468)();
        } else {
            return func_8014F6F4();
        }
    }
    return 0;
}
