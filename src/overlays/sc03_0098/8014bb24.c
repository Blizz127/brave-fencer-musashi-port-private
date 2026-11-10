/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014BB24 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029178(s32 a0);
extern u8 D_80078E78[];
extern s16 D_80078EB4;

void func_8014BB24(s32 a0, s32 a1, s32 a2)
{
    u8 *base = D_80078E78;
    u16 cur;
    if (a2 != 0) {
        D_80078EB4 = (u16)D_80078EB4 + a1;
    } else {
        if ((func_80029178(0x1B) & 0xFF) != 0) {
            cur = D_80078EB4;
            if (cur < 0x3E7) {
                D_80078EB4 = cur + a1;
                if ((u16)(cur + a1) >= 0x3E8) {
                    D_80078EB4 = 0x3E7;
                }
            }
        } else {
            cur = D_80078EB4;
            if (cur < 0x1F4) {
                D_80078EB4 = cur + a1;
                if ((u16)(cur + a1) >= 0x1F5) {
                    D_80078EB4 = 0x1F4;
                }
            }
        }
    }
    if (*(u16 *)(base + 0x3A) < *(u16 *)(base + 0x3C)) {
        *(u16 *)(base + 0x3C) = *(u16 *)(base + 0x3A);
    }
}
