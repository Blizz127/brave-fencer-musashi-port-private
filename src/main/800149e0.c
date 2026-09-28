/* Exact retail word export for [800149E0,80014B10); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800149E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078DD2;
extern u8 func_80014C28(u32 a0);
extern u8 func_80014CF8(u32 a0, u32 a1);
extern u8 func_80014D30(u32 a0, u32 a1);

s32 func_800149E0(s32 a0) {
    u8 b0;
    u16 val;
    s32 c;
    u16 h1;
    u16 h2;
    u16 m1;
    u16 m2;
    u16 v1;

    b0 = a0 & 0xFF;
    val = *(u16*)((u32)&D_80078DD2 + (u32)(b0 * 76));
    if (val != 0) {
        return val;
    }

    c = func_80014C28(b0) & 0xFF;
    if (c != 'S') {
        if (c < 'T') {
            return 0;
        }
        if (c != 's') {
            return 0;
        }
    }

    b0 = a0 & 0xFF;
    h1 = func_80014D30(b0, 5) & 0xFF;
    h2 = func_80014D30(b0, 4) & 0xFF;
    m1 = func_80014CF8(b0, 5) & 0xFF;
    m2 = func_80014CF8(b0, 4) & 0xFF;

    v1 = 0;
    if (h1 == 0x80) {
        if (m1 != h1) {
            if (m1 >= 0x80) {
                v1 = 0x4000;
            } else {
                v1 = 0x1000;
            }
        }
    }

    if (h2 != 0x80) {
        return v1;
    }
    if (m2 != h2) {
        if (m2 < 0x80) {
            v1 |= 0x8000;
        } else {
            v1 |= 0x2000;
        }
    }
    return v1;
}
