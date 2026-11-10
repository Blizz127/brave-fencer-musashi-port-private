/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80163764 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8014C278(s32 a0, s32 a1, s32 a2);
extern s32 func_801506A4();
extern u8 D_801202A0[];

s32 func_80163764(s32 a0)
{
    s32 counter;
    u8 *ptr;
    s32 loaded_value;
    counter = 0;
    ptr = D_801202A0;
    loaded_value = *(s32 *)(a0 + 0x4C);
    while (1) {
        if (*(u16 *)ptr != 0) {
            if ((*(u16 *)(ptr + 0x5C) & 0x100) != 0) {
                if (func_8014C278(a0, (s32)ptr, 0x40) != 0) {
                    ((s32 (*)(s32, s32))func_801506A4)(loaded_value, (s32)ptr);
                    return 1;
                }
            }
        }
        counter++;
        if ((u32)counter >= 0x60) {
            break;
        }
        ptr += 0x10C;
    }
    return 0;
}
