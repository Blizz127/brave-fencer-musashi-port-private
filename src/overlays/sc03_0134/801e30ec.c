/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E30EC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801789AC(s32 a0);
extern void func_8012A828(s32 a0, s32 a1);
extern s32 func_8012BA10(s32 a0, s32 a1);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern void func_80178D18(s32 a0);

void func_801E30EC(void *param_1) {

    extern s32 D_801E37E8[];
    extern s32 D_801E37DC[];
    extern s32 D_801E37F4[];

    switch (*(s16 *)((s32)param_1 + 0xFC)) {
    case 0: {
        s32 v0 = func_8012BA10((s32)param_1, 0x10);
        s32 cur;
        s32 target;
        *(u16 *)(*(s32 *)((s32)param_1 + 0x20) + 0x12) =
            (*(u16 *)(*(s32 *)((s32)param_1 + 0x20) + 0x12) + v0) & 0xFFF;
        cur = *(s32 *)((s32)param_1 + 0x90);
        target = D_801E37E8[*(s16 *)((s32)param_1 + 0x70)];
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
        target = D_801E37DC[*(s16 *)((s32)param_1 + 0x70)];
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
        target = D_801E37DC[*(s16 *)((s32)param_1 + 0x70)];
        if (cur != target) {
            func_8012A828((s32)param_1, target);
        }
        break;
    }
    case 3: {
        s32 cur = *(s32 *)((s32)param_1 + 0x90);
        s32 target = D_801E37F4[*(s16 *)((s32)param_1 + 0x70)];
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
