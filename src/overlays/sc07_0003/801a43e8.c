/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A43E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8002D4C8(s32 a0, s32 a1);

void func_801A43E8(void *a0) {
    switch (*(u16 *)((s32)a0 + 0x5E)) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 35:
        func_8002D4C8(0xC33, 0);
        *(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0xE8) += 0x2000;
        break;
    case 11:
    case 12:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
        func_8002D4C8(0xC33, 0);
        *(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0xE8) += 0x4000;
        break;
    case 36:
        func_8002D4C8(0xC33, 0);
        *(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0xE8) += 0x4000;
        break;
    default:
        *(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0xE8) += 0x2000;
        break;
    }
    if (*(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0xE8) > 0x10000) {
        *(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0xE8) = 0x10000;
    }
}
