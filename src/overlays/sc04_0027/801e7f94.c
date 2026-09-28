/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E7F94 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D24A0(s32);
extern void func_801E7FD8(void);
extern void func_8002AF18(void);
extern u16 D_80115112;

void func_801E7F94(void) {
    u16 *p = &D_80115112;
    ((void (*)(u32))func_800D24A0)(0x5);
    func_801E7FD8();
    func_8002AF18();
    *p = *p + 1;
}
