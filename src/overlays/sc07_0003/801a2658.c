/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A2658 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801F1FD8;
extern void func_8012EC04(s32 a0, s32 a1, s32 *a2);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern u8 *func_8012913C(s32 a0);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_8012C51C(void *a0, s32 a1);

void func_801A2658(s32 arg0, s32 arg1) {
    s32 buf[8];
    s16 vec[3];
    struct {
        s16 f0, f1, f2, f3, f4, f5, f6, f7;
        s32 f8;
    } eff;
    s32 i;
    u8 *ent;
    s32 delta;

    delta = *(s16 *)(arg1 + 0x6);
    if (*(s32 *)(arg0 + 0x90) == (s32)&D_801F1FD8) {
        delta -= 1;
    }
    func_8012EC04(arg0, delta, buf);
    func_8012F14C((s32)buf, arg1, (s32)vec);

    for (i = 0; i < 0x1000; i += 0x100) {
        ent = func_8012913C(0x22);
        if (ent != 0) {
            *(s16 *)(ent + 0x6) = vec[0];
            *(s16 *)(ent + 0xA) = vec[1];
            *(s16 *)(ent + 0xE) = vec[2];
            *(s32 *)(ent + 0x10) = func_80047948(i) * 320;
            *(s32 *)(ent + 0x18) = func_8004787C(i) * 320;
            *(s16 *)(ent + 0x34) = 0x4000;
            *(u16 *)(*(s32 *)(ent + 0x20) + 0x2C) = 0xC002;
        }
    }

    eff.f3 = 0x376;
    eff.f4 = 0;
    eff.f5 = 0;
    eff.f8 = 0;
    eff.f7 = 0;
    eff.f6 = 0x7FFF;
    eff.f0 = vec[0];
    eff.f1 = vec[1];
    eff.f2 = vec[2];

    for (i = 0; i < 8; i++) {
        func_8012C51C(&eff, arg0);
    }
}
