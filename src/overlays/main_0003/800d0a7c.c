/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0A7C - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_800D0A7C(void) {
    extern u8 D_800AF630[];
    extern volatile s32 D_800EC890;
    extern void func_800146B0(s32 a0);
    extern void func_800118AC();
    extern void func_800D12D0(void);
    register u8 *var_s0 = D_800AF630;

    D_800EC890 = D_800EC890 - 4;
    if (D_800EC890 < 0) {
        D_800EC890 = 0;
        func_800146B0(1);
        *(s32 *) (var_s0 + 0xA3E8) = 2;
        func_800118AC();
    } else {
        func_800D12D0();
    }
}
