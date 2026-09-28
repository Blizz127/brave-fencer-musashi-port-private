/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172414 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80161C24(s32, s32);
extern void func_8014C010(s32 a0, s32 a1);
extern u16 D_800B99DA;

void func_80172414(s32 a0) {
    if (*(u16 *)(a0 + 0xB8) & 0x2000) {
        func_80161C24(a0, *(u16 *)(a0 + 0x16E));
    }
    if (*(s32 *)(a0 + 0x2C) < (s32)0xFFF90000) {
        if ((D_800B99DA & 7) == 0) {
            func_8014C010(a0, 2);
        }
    }
}
