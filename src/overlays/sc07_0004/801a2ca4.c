/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A2CA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80016450(s32 a0, s32 a1);
extern s16 D_801F8868;
extern s16 D_801F886C;

void func_801A2CA4(void) {
    if (D_801F8868 != 0) {
        switch (D_801F8868) {
        case 1:
            D_801F886C = (u16)D_801F886C + 48;
            if (D_801F886C >= 96) {
                D_801F8868 = 2;
            }
            break;
        case 2:
            D_801F886C = (u16)D_801F886C - 24;
            if (D_801F886C < 0) {
                D_801F886C = 0;
            }
            if (D_801F886C == 0) {
                D_801F8868 = 0;
            }
            break;
        }
        func_80016450(*(u8 *)&D_801F886C, 1);
    }
}
