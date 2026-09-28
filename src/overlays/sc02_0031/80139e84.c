/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80139E84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);

void func_80139E84(s32 a0) {
    s32 s0 = a0;
    if (*(u16 *)(s0 + 0xE) == 0) {
        *(s16 *)(s0 + 0x4) = 2;
    } else {
        func_80139A8C(s0);
        if ((*(s32 *)(s0 + 0x8) & 0x80020) != 0) {
            *(s16 *)(s0 + 0x4) = 2;
            *(s16 *)(s0 + 0xE) = 0;
            if ((*(s32 *)(s0 + 0x8) & 0x20000) == 0) {
                *(s32 *)(s0 + 0x8) = *(s32 *)(s0 + 0x8) & -0x21;
            }
        }
    }
    func_80139B18(s0);
}
