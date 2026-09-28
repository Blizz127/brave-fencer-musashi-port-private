/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157F64 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029178(s32 a0);
extern u16 func_80148800(s32 *a0);
extern void func_80149CB4(void);

s32 func_80157F64(s32 *a0) {
    if ((func_80029178(0x87) & 0xFF) != 0) {
        if ((func_80148800(a0) & 0x80) != 0) {
            ((void (*)(s32 *, s32))func_80149CB4)(a0, 5);
            return 1;
        }
    }
    return 0;
}
