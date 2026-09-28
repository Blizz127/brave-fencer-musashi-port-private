/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A2318 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012AD80(void);

s32 func_801A2318(s32 arg0) {
    s32 temp;

    temp = *(s32 *)(arg0 + 0xD8);
    ((void (*)(s32))func_8012AD80)(temp);

    if (--*(s32 *)(arg0 + 0xF8) == 0) {
        *(s32 *)(temp + 0x14) = 0x60000;
        func_8002D4C8(4, 0xC36);
        return 1;
    }
    return 0;
}
