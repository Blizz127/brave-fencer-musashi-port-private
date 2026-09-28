/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801699D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80169A4C(s32 a0, s32 a1);
extern void func_800D22E4(s32 a0);
extern void func_80146C3C();

void func_801699D0(void *arg0) {
    s32 temp_v1;
    temp_v1 = *(s32 *)((u8 *)arg0 + 0x1C);
    if (temp_v1 < 0xF) {
        *(s32 *)((u8 *)arg0 + 0x30) = 0xC0 - temp_v1 * 8;
        func_80169A4C((s32)arg0, (s32)arg0 + 0x38);
        func_800D22E4((s32)arg0);
        *(s32 *)((u8 *)arg0 + 0x14) = *(s32 *)((u8 *)arg0 + 0x14) + 0x10000;
        *(s32 *)((u8 *)arg0 + 0x1C) = *(s32 *)((u8 *)arg0 + 0x1C) + 1;
    } else {
        ((void (*)(s32))func_80146C3C)((s32)arg0);
    }
}
