/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE234 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801789AC(s32 a0);
extern void func_80178CBC(s32 a0, s32 a1);
extern void func_80174438(s32 a0);
extern u8 *D_80126B10;

void func_801EE234(void *param_1) {

    extern s32 D_801EE4DC;

    switch (*(u16 *)((s32)param_1 + 0x34)) {
    case 0:
        if (((s32 (*)(void))func_801789AC)() != 0) {
            func_80178CBC((s32)param_1, (s32)&D_801EE4DC);
            *(u16 *)((s32)param_1 + 0x34) = 1;
        }
        break;
    case 1:
        if (func_801789AC((s32)param_1) != 0) {
            func_80174438((s32)D_80126B10);
            *(u16 *)((s32)param_1 + 0x34) = 2;
        }
        break;
    case 2:
        break;
    }
}
