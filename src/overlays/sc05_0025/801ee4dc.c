/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE4DC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012BA10(s32 a0, s32 a1);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern void func_8012A828(s32 a0, s32 a1);
extern s32 func_801789AC(s32 a0);
extern void func_80178D18(s32 a0);

void func_801EE4DC(void *param_1) {

    extern s32 D_801EEBB0[];
    extern s32 D_801EEBA4[];
    extern s32 D_801EEBBC[];

    switch (*(s16 *)((s32)param_1 + 0xFC)) {
    case 0: {
        s32 v0 = func_8012BA10((s32)param_1, 0x10);
        s32 cur;
        s32 target;
        *(u16 *)(*(s32 *)((s32)param_1 + 0x20) + 0x12) =
            (*(u16 *)(*(s32 *)((s32)param_1 + 0x20) + 0x12) + v0) & 0xFFF;
        cur = *(s32 *)((s32)param_1 + 0x90);
        target = D_801EEBB0[*(s16 *)((s32)param_1 + 0x70)];
        if (cur != target) {
            func_8012A828((s32)param_1, target);
        }
        break;
    }
    case 1: {
        s32 v0 = func_8012BA10((s32)param_1, 0x10);
        s32 cur;
        s32 target;
        *(u16 *)(*(s32 *)((s32)param_1 + 0x20) + 0x12) =
            (*(u16 *)(*(s32 *)((s32)param_1 + 0x20) + 0x12) + v0) & 0xFFF;
        cur = *(s32 *)((s32)param_1 + 0x90);
        target = D_801EEBA4[*(s16 *)((s32)param_1 + 0x70)];
        if (cur != target) {
            func_8012A828((s32)param_1, target);
        }
        break;
    }
    case 2: {
        s32 v0 = func_8012B608(*(s16 *)(*(s32 *)((s32)param_1 + 0x20) + 0x12), 0x600, 8);
        s32 cur;
        s32 target;
        *(u16 *)(*(s32 *)((s32)param_1 + 0x20) + 0x12) =
            (*(u16 *)(*(s32 *)((s32)param_1 + 0x20) + 0x12) + v0) & 0xFFF;
        cur = *(s32 *)((s32)param_1 + 0x90);
        target = D_801EEBA4[*(s16 *)((s32)param_1 + 0x70)];
        if (cur != target) {
            func_8012A828((s32)param_1, target);
        }
        break;
    }
    case 3: {
        s32 cur = *(s32 *)((s32)param_1 + 0x90);
        s32 target = D_801EEBBC[*(s16 *)((s32)param_1 + 0x70)];
        if (cur != target) {
            func_8012A828((s32)param_1, target);
        }
        break;
    }
    }

    if (*(s16 *)((s32)param_1 + 0x70) == 0) {
        if (func_801789AC((s32)param_1) != 0) {
            func_80178D18((s32)param_1);
            *(s16 *)((s32)param_1 + 0x70) = 2;
        }
    }
}
