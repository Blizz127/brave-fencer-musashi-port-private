/* Exact retail overlay 0010 export [800CEF5C,800CEFB0), offset 0x20164. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CEF5C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8001B324(void);
extern void func_8001C0C8(void);
extern void func_80011A3C(void);
extern u8  D_800B9A12;
extern s8  D_800B9A10;
extern u8  D_800B9A17;
extern s16 D_800B9A0E;

void func_800CEF5C(void) {
    volatile int loc[2];
    func_8001B324();
    D_800B9A12 = 1;
    D_800B9A10 = 0;
    D_800B9A17 = 0;
    func_8001C0C8();
    D_800B9A0E = 0;
    func_80011A3C();
}
