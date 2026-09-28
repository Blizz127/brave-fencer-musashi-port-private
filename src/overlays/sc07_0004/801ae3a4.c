/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AE3A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012C218(void *a0);

void func_801AE3A4(void *arg0) {
    s16 val;
    s32 *ptr;
    u16 rd;

    val = *(s16 *)(*(s32 *)((char *)arg0 + 0x20) + 0x18);
    if (val >= 0x2801) {
        func_8012C218(arg0);
    } else {
        *(s16 *)(*(s32 *)((char *)arg0 + 0x20) + 0x18) = val + 0x180;
        ptr = (s32 *)(*(s32 *)((char *)arg0 + 0x20));
        rd = *(u16 *)((char *)ptr + 0x18);
        *(u16 *)((char *)ptr + 0x1C) = rd;
        *(u16 *)((char *)ptr + 0x1A) = rd;
    }
}
