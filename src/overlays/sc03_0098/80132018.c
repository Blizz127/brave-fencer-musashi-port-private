/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80132018 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(int, int);
extern void (*D_80185848[])(void);
extern s32 D_8018584C[];

void func_80132018(void *a0)
{
    s32 v0;

    v0 = ((int (*)(void))func_8012C1B8)();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
    } else {
        func_8001C214(v0, 0);
        *(s16 *)((s32)a0 + 0x5c) = 0x80;
        *(u16 *)((s32)a0 + 0x2) += 1;
        *(s32 *)((s32)a0 + 0x58) = (s32)&D_8018584C[(*(u16 *)((s32)a0 + 0x70) & 0xfff) * 5];
        *(s32 *)((s32)a0 + 0xdc) = (s32)D_80185848[(*(u16 *)((s32)a0 + 0x70) & 0xfff) * 5];
        *(u16 *)((s32)a0 + 0xfc) = (*(u16 *)((s32)a0 + 0x70) >> 0xc) << 9;
    }
}
