/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165718 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80165A20(s32 a0);
extern u8 D_80078EC1;

void func_80165718(s32 a0) {
    switch (D_80078EC1) {
    case 3:
    case 0xC:
    case 0x18:
        func_80165A20(a0);
        break;
    }
}
