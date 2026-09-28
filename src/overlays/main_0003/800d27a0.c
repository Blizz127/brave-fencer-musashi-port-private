/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D27A0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80059888(void *a0, s32 a1, s32 a2, s32 a3);
extern s32 D_800EC9F4;
extern s32 D_800EC9F8;
extern s32 D_800D9484;
extern s32 D_800D9488;
struct UnkS1 { s32 pad0; s32 f4; s32 pad8; s32 fC; s32 pad10; s32 pad14; s32 f18; u32 f1C; };

s32 func_800D27A0(void* arg0, struct UnkS1* arg1) {
    s32 sp10[2];
    u16 sp18[4];
    s32 ret;
    s32 i;

    for (i = 0x8000; i != 0; i--) {
        if (func_80046C38(&sp10[0], &sp10[1]) == 0) {
            goto found;
        }
    }
    return 0;
found:
    if (*(u32*)(sp10[1] + 8) >= arg1->fC) {
        D_800EC9F4 = 1;
    }
    if (*(u32*)(sp10[1] + 8) >= arg1->fC - 15) {
        D_800EC9F8 = 1;
    } else {
        D_800EC9F8 = 0;
    }
    if (D_800D9484 != *(u16*)(sp10[1] + 0x10) || D_800D9488 != *(u16*)(sp10[1] + 0x12)) {
        u16 cur1;
        u16 cur2;
        sp18[0] = 0;
        sp18[1] = 0;
        sp18[2] = arg1->f4 != 0 ? (arg1->f18 * 3) / 2 : *(u16*)&arg1->f18;
        sp18[3] = arg1->f1C * 2;
        if (arg1->f4 != 0) {
            func_80059888(sp18, 0, 0, 0);
        } else {
            func_80059888(sp18, 0x40, 0x40, 0x40);
        }
        cur1 = *(u16*)(sp10[1] + 0x10);
        cur2 = *(u16*)(sp10[1] + 0x12);
        D_800D9484 = cur1;
        D_800D9488 = cur2;
    }
    {
        u16 t = arg1->f4 != 0 ? (D_800D9484 * 3) / 2 : *(u16*)&D_800D9484;
        u16 g;
        ret = sp10[0];
        g = *(u16*)&D_800D9488;
        *(u16*)(arg0 + 0x24) = t;
        *(u16*)(arg0 + 0x1C) = t;
        *(u16*)(arg0 + 0x26) = g;
        *(u16*)(arg0 + 0x1E) = g;
        *(u16*)(arg0 + 0x32) = g;
    }
    return ret;
}
