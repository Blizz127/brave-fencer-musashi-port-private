/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139B18 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_8012752C;
extern s32 func_80014E80(s32 a0, s32 a1);
extern void func_8001931C(void);

void func_80139B18(s32 a0) {
    s32 m;
    s32 p;
    if (*(s32 *)(a0 + 8) & 0x6000) {
        return;
    }
    if ((s16)func_80014E80(0, 0x10) == 0) {
        return;
    }
    m = *(s32 *)(a0 + 8);
    if (m & 0x10000) {
        *(s32 *)(a0 + 8) = m & 0xFFFEFFFF;
        func_8001931C();
        D_8012752C = 0;
    }
    if (*(s32 *)(a0 + 8) & 0x2000) {
        *(s16 *)(a0 + 4) = 0xD;
        return;
    }
    *(s16 *)(a0 + 4) = 0xC;
    p = *(s32 *)(a0 + 0x40);
    *(s32 *)(a0 + 8) = *(s32 *)(a0 + 8) & 0xFFFFEFFF;
    if (p == 0) {
        return;
    }
    if (*(u16 *)(a0 + 0x18) == 0) {
        return;
    }
    *(s16 *)p = 3;
}
