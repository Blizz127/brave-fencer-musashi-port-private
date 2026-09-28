/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0740 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_800EC888;
extern s16 D_800EC894;
extern s16 D_800EC898;
extern s32 D_800EC88C;
extern u8 D_800AF630[];
extern void func_800D12D0(void);
extern s32 func_800149E0(s32);
extern void func_8002D4C8(s32, s32);
extern void func_800167B8(s32);
extern void func_800118AC();

void func_800D0740(void) {
    register u8 *base = D_800AF630;
    s32 sp10;

    func_800D12D0();
    D_800EC888 = func_800149E0(0);
    sp10 = 0;
    if (D_800EC888 & 0x4000) {
        func_8002D4C8(0x9C1, 0);
        sp10 = 1;
        D_800EC894++;
        if (D_800EC894 >= 3) {
            D_800EC894 = 0;
        }
    } else if (D_800EC888 & 0x1000) {
        func_8002D4C8(0x9C1, 0);
        sp10 = 1;
        D_800EC894--;
        if (D_800EC894 < 0) {
            D_800EC894 = 2;
        }
    }
    D_800EC898 = 0;
    switch (D_800EC894) {
    case 0:
        if (D_800EC888 & 0x800) {
            func_8002D4C8(0x9C0, 0);
            func_800167B8(4);
            func_800118AC();
        }
        break;
    case 1:
    case 2:
        if (D_800EC888 & 0x800) {
            func_8002D4C8(0x9C0, 0);
            func_800167B8(4);
            func_800118AC();
        }
        break;
    }
    if (D_800EC88C > 0) {
        if (--D_800EC88C == 0) {
            func_800167B8(4);
            D_800EC894 = 4;
            func_800118AC();
        }
    }
}
