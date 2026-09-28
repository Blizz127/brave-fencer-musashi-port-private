/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D06BC - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D12D0(void);
extern void func_800118AC(void);
extern s32 D_800EC890;
extern u8 D_800AF630[];

void func_800D06BC(void) {
    register u8 *base;

    base = &D_800AF630;
    func_800D12D0();
    D_800EC890 += 4;
    if (D_800EC890 >= 0x80) {
        D_800EC890 = 0x80;
        func_800118AC();
    }
}
