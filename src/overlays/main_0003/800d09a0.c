/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D09A0 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D12D0(void);
extern s16 D_800EC898;
extern s16 D_800EC894;
extern void func_800D1D14(s32, s32);
extern void func_800118AC();
extern u8 D_800AF630[];

void func_800D09A0(void) {
    register u8 *base = D_800AF630;

    func_800D12D0();
    D_800EC898++;
    if ((s16)(D_800EC898 & 4)) {
        func_800D1D14(D_800EC894, 1);
    } else {
        func_800D1D14(D_800EC894, 0);
    }
    if (D_800EC898 >= 0x21) {
        func_800118AC();
    }
}
