/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016D5EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern short func_8016CF04();
extern void func_80146C3C();
extern void func_8012A568(void (*a0)(void));

void func_8016D5EC(s32 *a0) {
    u16 *rec = (u16 *)a0[8];   /* lw 0x20(s0) */
    rec[0xC] -= 0x60;          /* 0x18 */
    rec[0xD] -= 0x60;          /* 0x1A */
    if ((s16)((s32 (*)(s32, s32))func_8016CF04)((s32)a0, 2) != 0) {
        ((void (*)(s32 *))func_80146C3C)(a0);
    }
}
