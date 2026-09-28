/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AE220 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012C588(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_801AD7EC(s32 a0);

void func_801AE220(s32 a0) {
    s32 v20;
    s32 r;
    u16 tmp;
    s16 val0;

    switch (*(u16 *)(a0 + 0x34)) {
    case 0:
        func_8012C588(0x3A0, a0);
        *(s32 *)(a0 + 0x1C) = 6;
        *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) + 1;
        func_8002D4C8(0xB4E, 0);
        break;
    case 1:
        if (func_8012BEE8(a0) != 0) {
            func_8012C588(0x3A0, a0);
            *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) + 1;
            func_801AD7EC(a0);
        }
        break;
    case 2:
        break;
    case 3:
        break;
    }

    val0 = *(s16 *)(*(s32 *)(a0 + 0x20) + 0x18);
    if (val0 < 0x2400) {
        *(s16 *)(*(s32 *)(a0 + 0x20) + 0x18) = val0 + 0xC0;
        v20 = *(s32 *)(a0 + 0x20);
        tmp = *(u16 *)(v20 + 0x18);
        *(u16 *)(v20 + 0x1C) = tmp;
        *(u16 *)(v20 + 0x1A) = tmp;
        r = *(s32 *)(a0 + 0xCC);
        if (r != 0) {
            u16 tmp2 = *(u16 *)(r + 0x18) + 0xC0;
            *(u16 *)(r + 0x18) = tmp2;
            *(u16 *)(r + 0x1C) = tmp2;
            *(u16 *)(r + 0x1A) = tmp2;
        }
    }
}
