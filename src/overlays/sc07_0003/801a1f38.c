/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1F38 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80016714(s8 *a0, s32 a1);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_800D0C48(s32 a0);
extern s32 func_80178B18(s32 a0, s32 a1);
extern void func_8017C068(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern s16 D_801A6964;
extern s16 D_801A6966;
extern s16 D_801A6968;
extern s16 D_801A696C;
extern s16 D_801A6AE4;
extern u8 D_801F1A58[];
extern s32 D_801F4358;

void func_801A1F38(s32 arg0) {
    s32 s0 = arg0;

    D_801A6964 = 0;
    D_801A6966 = -0x90;
    D_801A6968 = 0;

    D_801A696C = *(u16 *)(*(s32 *)(s0 + 0x20) + 0x12) & 0xFFF;

    func_80178B18((s32)s0, (s32)&D_801A6AE4);

    *(s16 *)(s0 + 0x2) = 0x18;
    *(s16 *)(s0 + 0x34) = 0;
    *(s16 *)(s0 + 0x98) = 0;
    *(s32 *)(s0 + 0x1C) = 0;
    *(s32 *)(s0 + 0xE4) = 0x10000;
    func_8017C068();

    func_8012A828((s32)s0, D_801F1A58);
    func_8012B178((s32)s0, 0x30000);
    func_800D0C48(1);
    func_8002D4C8(0xC73, 0);

    if (D_801F4358 != 0) {
        func_80016714((s8 *)D_801F4358, 0x38);
        D_801F4358 = 0;
    }
}
