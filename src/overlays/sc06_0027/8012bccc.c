/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012BCCC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80013478(s32 a0, s32 a1);
extern s16 D_80126CBA;
extern s32 D_80126B58;

s32 func_8012BCCC(s32 a0) {
    s32 *p = &D_80126B58;
    if (D_80126CBA != 0) {
        return 0x7FFFFFFF;
    }
    return func_80013478(a0 + 4, (s32)p + 0x15C);
}
