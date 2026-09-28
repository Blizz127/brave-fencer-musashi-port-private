/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017385C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s16 D_80126B30;
extern void func_80171A1C(u8 *a0);
extern s32 func_80174650(s32);

void func_8017385C(u8 *a0) {
    switch (D_80126B30) {
    case 0:
    default:
        *(u16 *)(a0 + 0xAC) |= 0x80;
        *(u16 *)(a0 + 0xAA) |= 0x80;
        break;
    case 1:
        *(u16 *)(a0 + 0xAC) |= 0x10;
        *(u16 *)(a0 + 0xAA) |= 0x10;
        break;
    }
    func_80171A1C(a0);
    func_80174650((s32)a0);
}
