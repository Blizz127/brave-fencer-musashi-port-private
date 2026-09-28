/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012C218 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80016714(void *a0, s32 a1);

void func_8012C218(void *a0) {
    u16 *p = ((u16 **)a0)[8];   /* 0x20/4 */
    if (p) {
        s32 a1;
        switch (*p) {
        case 2:  a1 = 0x38; break;
        case 1:  a1 = 0x84; break;
        default: goto skip;
        }
        func_80016714(p, a1);
    }
skip:
    func_80016714(a0, 0x10C);
}
