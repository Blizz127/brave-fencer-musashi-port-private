/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A108C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801A108C(s32 arg0)
{
    extern s32 func_8012C588(s32 a0, s32 a1);
    extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);

    s32 temp;

    temp = *(s32 *)(arg0 + 0x1C);
    if (temp == (temp / 24) * 24) {
        if (*(s16 *)(arg0 + 0x100) == *(s16 *)(arg0 + 0x102)) {
            func_8012C658(0x34, 1, arg0);
        } else {
            func_8012C588(0x34, arg0);
        }
        *(u16 *)(arg0 + 0x100) = *(u16 *)(arg0 + 0x100) + 1;
    }
}
