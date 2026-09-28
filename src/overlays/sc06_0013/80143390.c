/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80143390 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80142DB8(s32 *a0);
extern s32 func_80142D38(s32 *a0);
extern void func_80142BB4(s32 *a0, s32 a1, s32 a2);

void func_80143390(s32 *a0) {
    if (func_80142DB8(a0) == 1) {
        func_80142BB4(a0, 1, 3);
    } else if (func_80142D38(a0) == 1) {
        func_80142BB4(a0, 0, 3);
    }
}
