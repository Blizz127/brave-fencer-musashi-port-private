/* Complete SC02 retail span [80182328,801824E4).
 * SC02 820xx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80182328 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_8012A568(void (*a0)(void));
extern void func_8012AD80(s32 a0);
extern void func_80182674(s32 a0, s16 *vec, s32 count, s32 flag);
extern void func_80182848(void *a0, u8 *a1, s32 a2, s32 a3, s32 a4);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern void func_8013C98C(void);
extern void func_8013C9C4(void *a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern u16 D_80188E58;
extern u16 D_80188E5A;
extern u16 D_80188E5C;
extern u16 D_80188E60;
extern u16 D_80188E62;
extern u16 D_80188E64;
extern u8 D_80188E68[];
extern s32 func_80182618(s32 a0);

void func_80182328(void *a0)
{
    extern void (*D_80188F48[])(void);
    s16 sp18[3];
    s16 sp20[3];
    s16 sp28[3];
    s32 v0;
    s32 pad[2];

    func_8012AD80((s32)a0);

    sp18[0] = *(u16 *)((s8 *)a0 + 0x3A);
    sp18[1] = *(u16 *)((s8 *)a0 + 0x3E);
    sp18[2] = *(u16 *)((s8 *)a0 + 0x42);

    sp20[0] = *(u16 *)((s8 *)a0 + 0x6);
    sp20[1] = *(u16 *)((s8 *)a0 + 0xA);
    sp20[2] = *(u16 *)((s8 *)a0 + 0xE);

    sp28[0] = sp20[0] + D_80188E60;
    sp28[1] = sp20[1] + D_80188E62;
    sp28[2] = sp20[2] + D_80188E64;

    func_80182674((s32)a0, sp28, 5, 0);

    if ((*(s32 *)((s8 *)a0 + 0x1C) & 7) == 0) {
        func_80182848(a0, D_80188E68, 5, 0, 0);
        func_80182848(a0, D_80188E68, 5, 0, 1);
    }

    sp18[0] = sp18[0] + D_80188E58;
    sp18[1] = sp18[1] + D_80188E5A;
    sp18[2] = sp18[2] + D_80188E5C;

    sp20[0] = sp20[0] + D_80188E58;
    sp20[1] = sp20[1] + D_80188E5A;
    sp20[2] = sp20[2] + D_80188E5C;

    *(s32 *)((s8 *)a0 + 0x1C) = *(s32 *)((s8 *)a0 + 0x1C) + 1;
    v0 = func_80133784(1, sp18, (s32)sp20);

    if ((v0 & 0x2000) != 0) {
        *(u16 *)((s8 *)a0 + 0x2) = 4;
        *(s32 *)((s8 *)a0 + 0x1C) = 0x3C;
        *(u16 *)((s8 *)a0 + 0x34) = 0;
        func_8013C98C();
        func_8013C9C4(&D_80188F48);
        *(s32 *)((s8 *)a0 + 0xE0) = 3;
        func_8002D4C8(0x63E, 0);
    }

    func_80182618(a0);
}
