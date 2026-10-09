/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80156ECC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80156ECC(int param_1, int param_2, int param_3, int param_4, int param_5) {
    extern void func_80156FA8(s16 *param_1, s16 *param_2, s16 *param_3);
    extern void func_80147478(s32 a0);
    extern void func_80149350(s32 arg0, s32 a1, s32 a2);
    unsigned short uVar1;
    func_80156FA8(param_3, param_4, param_5);
    ((s32 (*)(s32))func_80147478)(param_1);
    ((s32 (*)(s32, s32, s32))func_80149350)(param_1, param_2, param_2);
    uVar1 = *(unsigned short *)(param_3 + 6);
    if (*(short *)(param_3 + 6) == 0) {
        ((s32 (*)(s32, s32, s32))func_80149350)(param_1, param_3, param_3);
        *(unsigned short *)(param_3 + 6) = uVar1;
    }
    uVar1 = *(unsigned short *)(param_4 + 6);
    if (*(short *)(param_4 + 6) == 0) {
        ((s32 (*)(s32, s32, s32))func_80149350)(param_1, param_4, param_4);
        *(unsigned short *)(param_4 + 6) = uVar1;
    }
    uVar1 = *(unsigned short *)(param_5 + 6);
    if (*(short *)(param_5 + 6) == 0) {
        ((s32 (*)(s32, s32, s32))func_80149350)(param_1, param_5, param_5);
        *(unsigned short *)(param_5 + 6) = uVar1;
    }
}
