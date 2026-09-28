/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017E358 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};

void func_8017E358(s32 param_1) {
    s32 tbl;
    s32 obj;

    tbl = *(s32 *)(param_1 + 0x4C);
    obj = *(s32 *)(param_1 + 0x20);
    *(s32 *)(param_1 + 0x04) = *(s32 *)(tbl + 0x04);
    *(s32 *)(param_1 + 0x08) = *(s32 *)(tbl + 0x08);
    *(s32 *)(param_1 + 0x0C) = *(s32 *)(tbl + 0x0C);
    *(u16 *)(obj + 0x12) += *(u16 *)(*(s32 *)(param_1 + 0x58) + 0x06);
}
