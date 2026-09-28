/* Complete SC02 scene routine, independently matched ordinary C. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801284F0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80175308();
extern void func_8016E8F0(void);
extern void func_80175494(void);
extern void func_80011C10(void);
extern u8 D_800B9A64;

void func_801284F0(void) {
    func_80175308();
    func_8016E8F0();
    if (D_800B9A64 != 0) {
        func_80175494();
    }
    func_80011C10();
}
