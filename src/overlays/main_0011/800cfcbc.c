/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CFCBC - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_800CFCBC(void) {
    extern s32 D_800D4C94;
    extern void func_800D0964(void);
    extern void func_800D0BDC(void);
    extern void func_800D1254(void);
    extern void func_800D1B00(void);
    extern void func_800D235C(void);
    extern void func_800D2BC4(void);

    if (D_800D4C94 != 0) {
        if (D_800D4C94 > 0) {
            func_800D0964();
        }
        if (D_800D4C94 >= 2) {
            func_800D0BDC();
        }
        if (D_800D4C94 >= 3) {
            func_800D1254();
        }
        if (D_800D4C94 >= 4) {
            func_800D1B00();
        }
        if (D_800D4C94 >= 5) {
            func_800D235C();
        }
        if (D_800D4C94 >= 6) {
            func_800D2BC4();
        }
    }
}
