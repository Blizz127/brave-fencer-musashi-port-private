/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80169BBC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
extern void func_800D2318(void);
extern void func_80049A1C(void *a0, void *a1);
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_800D222C(void *a0, void *a1, s32 a2);
extern void func_8004D504(void *a0, void *a1, void *a2);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern void func_80048D9C(void *a0, void *a1);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern void func_80146C3C(void);

void func_80169BBC(s32 arg0) {

    extern s32 D_801269A4;
    extern s32 D_801269A8;
    extern s32 D_801269AC;
    extern u16 D_8018032C[];
    extern u8 D_8018039C[];
    extern u8 D_801803CC[];
    extern u8 D_80196600[];
    u16 rot[4];
    s16 vec[4];
    s32 pos[4];
    s16 mtx[16];
    s32 p1;
    s32 s2;

    func_800D2318();
    rot[0] = *(u16 *)(arg0 + 0x12);
    rot[1] = *(u16 *)(arg0 + 0x16);
    rot[2] = 0;
    func_80049A1C(rot, mtx);
    vec[0] = 0;
    vec[1] = -2;
    vec[2] = -0x14;
    func_80048FBC(mtx, vec, vec);
    *(u16 *)(arg0 + 6) = *(u16 *)(arg0 + 6) + (u16)vec[0];
    *(u16 *)(arg0 + 0xA) = *(u16 *)(arg0 + 0xA) + (u16)vec[1];
    *(u16 *)(arg0 + 0xE) = *(u16 *)(arg0 + 0xE) + (u16)vec[2];
    p1 = func_80146A6C(9, (void *)arg0, *(s16 *)(arg0 + 6), *(s16 *)(arg0 + 0xA),
                       *(s16 *)(arg0 + 0xE), 0, 0);
    if (p1 != 0) {
        *(u16 *)(p1 + 0x12) = rot[0];
        *(u16 *)(p1 + 0x16) = rot[1];
        *(u16 *)(p1 + 0x1A) = rot[2];
    }
    func_80146A6C(0xC, (void *)arg0, *(s16 *)(arg0 + 6), *(s16 *)(arg0 + 0xA),
                  *(s16 *)(arg0 + 0xE), 0, 0);
    s2 = func_800D222C((void *)arg0, D_801803CC, 0x17);
    if (s2 != 0) {
        *(s32 *)(arg0 + 0x20) = s2;
        rot[0] = rot[0] + D_8018032C[*(s32 *)(arg0 + 0x30)];
        rot[1] = rot[1] - 0x400;
        func_80049A1C(rot, mtx);
        pos[0] = D_801269A4 - *(s16 *)(arg0 + 6);
        pos[1] = D_801269A8 - *(s16 *)(arg0 + 0xA);
        pos[2] = D_801269AC - *(s16 *)(arg0 + 0xE);
        func_8004D504(mtx, pos, pos);
        rot[2] = -func_8004CFEC(pos[0], pos[1]);
        vec[0] = 0x400;
        vec[1] = -0x400;
        vec[2] = 0;
        func_80049A1C(vec, mtx);
        *(s32 *)(s2 + 0x34) = (s32)D_80196600;
        func_80049A1C(rot, D_80196600);
        func_80048D9C(D_80196600, mtx);
        *(u16 *)(s2 + 0x18) = 0x5000;
        *(u16 *)(s2 + 0x1A) = 0x2000;
        *(s32 *)(s2 + 4) = *(s32 *)(s2 + 4) | 0xC000140;
        func_80128EA8(s2, arg0 + 0x24, (s32)D_8018039C);
        *(u16 *)(arg0 + 2) = *(u16 *)(arg0 + 2) + 1;
    } else {
        ((void (*)(s32))func_80146C3C)(arg0);
    }
}
