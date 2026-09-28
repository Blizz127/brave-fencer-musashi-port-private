/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0268 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_800149E0(s32 arg0);
extern u8 D_800AF630[];
extern void func_8002D4C8(s32 arg0, s32 arg1);
extern s16 D_800EC894;
extern void func_800167B8(s32 arg0);
extern void func_800118AC(void);
extern void func_800D0D6C(void);

void func_800D0268(void) {
    u16 sp10;
    register u8 *p = D_800AF630;

    sp10 = func_800149E0(0);
    if (sp10 & 0x4000) {
        func_8002D4C8(0x9C1, 0);
        D_800EC894++;
        if (D_800EC894 >= 3) {
            D_800EC894 = 0;
        }
    } else if (sp10 & 0x1000) {
        func_8002D4C8(0x9C1, 0);
        D_800EC894--;
        if (D_800EC894 < 0) {
            D_800EC894 = 2;
        }
    }
    switch (D_800EC894) {
    case 0:
        if (sp10 & 0x800) {
            func_8002D4C8(0x9C0, 0);
            func_800167B8(4);
            func_800118AC();
        }
        break;
    case 1:
    case 2:
        if (sp10 & 0x800) {
            func_8002D4C8(0x9C0, 0);
            func_800167B8(4);
            func_800118AC();
        }
        break;
    }
    func_800D0D6C();
}
