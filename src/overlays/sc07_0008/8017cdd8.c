/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017CDD8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8017CF58(void);
extern void func_800167B8(s32 a0);

s32 func_8017CDD8(s32 a0) {
    func_8017CF58();
    func_800167B8(0);
    *(u8 *)(a0 + 0x15) += 1;
    return 0;
}
