/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A2F34 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8013240C(s32 a0);
extern void func_8001C924(s32 a0, void *a1);
extern void func_80132288(s32 *a0, s32 *a1, s32 a2);
extern void func_8014CBD8(void);
extern void func_801A3114(s32 *a0);
extern s32 D_80126B58[4];
extern u16 D_80126CE0;
extern u16 D_800B99DA;
extern s16 D_801AFB90;
extern s32 D_801AFAB8;
extern s32 D_801BC9EC;
extern u8 D_80063548[];
extern s32 D_801F8724;
extern s16 D_801F872A;
extern s32 D_801F8730;

void func_801A2F34(s32 a0) {
    s16 *p;
    s32 *s2;
    s32 *s0;
    s16 v1;
    s32 v0;

    v1 = *(s16 *)(a0 + 0xE6);
    s2 = D_80126B58;
    if (v1 == 0) {
        p = &D_801F872A;
        *p = (s16)D_80126CE0 >> 1;
        func_8013240C((s32)p - 6);
        if ((D_801F8730 & 0x4000) != 0) {
            *(u16 *)(a0 + 0xE6) = *(u16 *)(a0 + 0xE6) + 1;
        }
    } else if (v1 != 1) {
        if (*(s16 *)(a0 + 0x98) == 0 && *(s16 *)&D_80126CE0 >= D_801AFB90) {
            s0 = &D_801BC9EC;
            func_8001C924(*(s32 *)(a0 + 0x20), s0);
            *(s32 *)(*(s32 *)(a0 + 0x20) + 0x20) = (s32)D_80063548;
            *(s16 *)(a0 + 0xE6) = 0;
            func_80132288(&D_801F8724, &D_801AFAB8, *s0);
        }
    }
    if ((D_800B99DA & 1) != 0) {
        if (*(s16 *)((s32)s2 + 0x188) > 0) {
            *(s16 *)((s32)s2 + 0x188) = *(s16 *)((s32)s2 + 0x188) - 1;
        }
    }
    if (*(s16 *)((s32)s2 + 0x188) == 0) {
        v0 = *(u16 *)(a0 + 0xF8) + 1;
        *(u16 *)(a0 + 0xF8) = v0;
        if ((s16)v0 >= 0x19) {
            func_8014CBD8();
            func_801A3114((s32 *)a0);
        }
    } else {
        *(u16 *)(a0 + 0xF8) = 0;
    }
}
