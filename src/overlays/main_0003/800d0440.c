/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0440 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_800167F0(s32 arg0);
extern u8 D_800AF630[];
extern s16 D_800EC894;
extern void func_80059888(void *a0, s32 a1, s32 a2, s32 a3);
extern void func_800D0D6C(void);

void func_800D0440(void) {
    register u8 *p = D_800AF630;
    u16 rect[4];

    if ((u16) func_800167F0(4) != 0) {
        switch (D_800EC894) {
        case 0:
            *(u16 *) (p + 0xA3B6) = 1;
            *(u16 *) (p + 0xA3B8) = 2;
            break;
        case 1:
            *(u16 *) (p + 0xA3B6) = 1;
            *(u16 *) (p + 0xA3B8) = 0;
            break;
        case 2:
            *(u16 *) (p + 0xA3B6) = 1;
            *(u16 *) (p + 0xA3B8) = 1;
            break;
        case 4:
            *(u16 *) (p + 0xA3B6) = 1;
            *(u16 *) (p + 0xA3B8) = 4;
            break;
        }
        rect[0] = 0;
        rect[1] = 0;
        rect[2] = 0x140;
        rect[3] = 0x1E0;
        func_80059888(rect, 0, 0, 0);
    }
    func_800D0D6C();
}
