/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A27A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012EC04(s32 param_1, s32 param_2, s32 *param_3);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern u8 *func_8012913C(s32 a0);
extern s32 func_8012C51C(void *a0, s32 a1);

void func_801A27A4(void *a0, void *a1)
{
    s32 buf1[8];
    u16 pos[3];
    u8 *ent;
    s32 i;

    struct {
        u16 f0;
        u16 f2;
        u16 f4;
        u16 f6;
        u16 f8;
        u16 fA;
        u16 fC;
        u16 fE;
        s32 f10;
    } tmp;

    func_8012EC04((s32)a0, *(s16 *)((s32)a1 + 0x6), buf1);
    func_8012F14C((s32)buf1, (s32)a1, (s32)pos);

    ent = func_8012913C(0x22);

    if (ent != NULL) {
        *(u16 *)((s32)ent + 0x6)  = pos[0];
        *(u16 *)((s32)ent + 0xA)  = pos[1];
        *(u16 *)((s32)ent + 0xE)  = pos[2];
        *(s32 *)((s32)ent + 0x10) = -(*(s32 *)((s32)a0 + 0x10));
        *(s32 *)((s32)ent + 0x18) = -(*(s32 *)((s32)a0 + 0x18));
        *(u16 *)((s32)ent + 0x34) = 0x7001;
        *(u16 *)((s32)(*(s32 *)((s32)ent + 0x20)) + 0x2C) = 0xC002;
    }

    tmp.f0 = pos[0];
    tmp.f2 = pos[1];
    tmp.f4 = pos[2];
    tmp.f6 = 0x376;
    tmp.f8 = 0;
    tmp.fA = 0;
    tmp.f10 = 0;
    tmp.fE = 0;
    tmp.fC = 0x7FFF;

    for (i = 0; i < 2; i++) {
        func_8012C51C(&tmp, (s32)a0);
    }
}
