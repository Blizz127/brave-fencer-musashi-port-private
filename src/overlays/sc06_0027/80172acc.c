/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172ACC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);

void func_80172ACC(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x20);
    u16 v = *(u16 *)(a0 + 0x132);
    *(s16 *)(a0 + 0x136) = 0;
    *(u16 *)(p + 0x12) = v;
    func_80171A1C(a0);
    func_80174650((s32)a0);
}
