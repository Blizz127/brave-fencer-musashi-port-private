/* Complete SC02 retail span [8017EE3C,8017F050).
 * Live STOP 7ECB0 cluster; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017EE3C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w[8]; } Mtx8_8017DE10_8017EE3C;
extern void func_8012A568(void (*a0)(void));

void func_8017EE3C(s32 a0) {
    extern void func_80048FBC(void *a0, void *a1, void *a2);
    extern s32  func_8004CFEC(s32 a0, s32 a1);
    extern s16  D_801152B0;
    extern s16  D_801152B4;
    extern s32  func_80133784(s32 a0, void *a1, s32 a2);
    extern s32  func_8012CEB0(s32 a0, s32 a1, s32 a2);
    extern void func_8004A0DC(s32 a0, void *a1);
    extern Mtx8_8017DE10_8017EE3C D_800AE620;

    u8 in[8];
    u8 out[8];
    Mtx8_8017DE10_8017EE3C m;
    s32 base;
    register s32 ang __asm__("$2");
    s16 arg;

    *(s16 *)(in + 0) = *(u16 *)(a0 + 0x6) + *(u16 *)(a0 + 0x12);
    *(s16 *)(in + 2) = *(u16 *)(a0 + 0xA) + 8;
    *(s16 *)(in + 4) = *(u16 *)(a0 + 0xE) + *(u16 *)(a0 + 0x1A);
    *(s16 *)(out + 0) = *(u16 *)(a0 + 0x6);
    *(s16 *)(out + 2) = *(u16 *)(a0 + 0xA) + 8;
    *(s16 *)(out + 4) = *(u16 *)(a0 + 0xE);
    if ((func_80133784(1, &in[0], (s32)&out[0]) & 0xC000) != 0) {
        base = func_8004CFEC(D_801152B0, D_801152B4) & 0xFFF;
        ang = func_8004CFEC(*(s32 *)(a0 + 0x10), *(s32 *)(a0 + 0x18)) & 0xFFF;
        if ((s16)(ang - base) < 0) {
            ang += 0x480;
        } else {
            ang -= 0x480;
        }
        arg = base - ang;
        ang = *(u16 *)(a0 + 0x6);
        *(s16 *)(in + 0) = ang;
        *(s16 *)(in + 2) = *(u16 *)(a0 + 0xA);
        *(s16 *)(in + 4) = *(u16 *)(a0 + 0xE);
        m = D_800AE620;
        func_8004A0DC(arg, &m);
        *(s16 *)(out + 0) = *(u16 *)(a0 + 0x12);
        *(s16 *)(out + 2) = *(u16 *)(a0 + 0x16);
        *(s16 *)(out + 4) = *(u16 *)(a0 + 0x1A);
        func_80048FBC(&m, &out[0], &out[0]);
        *(s16 *)(out + 0) = *(u16 *)(a0 + 0x6) + ((s16)*(u16 *)(out + 0) >> 1);
        *(s16 *)(out + 2) = *(u16 *)(a0 + 0xA) + ((s16)*(u16 *)(out + 2) >> 1);
        *(s16 *)(out + 4) = *(u16 *)(a0 + 0xE) + ((s16)*(u16 *)(out + 4) >> 1);
        if ((func_8012CEB0((s32)&in[0], (s32)&out[0], 0) & 0x2000) != 0) {
            *(s16 *)(a0 + 0x6) = *(u16 *)(out + 0);
            *(s16 *)(a0 + 0xA) = *(u16 *)(out + 2);
            *(s16 *)(a0 + 0xE) = *(u16 *)(out + 4);
        }
    }
}
