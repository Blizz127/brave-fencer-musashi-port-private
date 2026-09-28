/* Complete SC02 retail span [80183BB0,80183D84).
 * Live STOP 83AC8 cluster; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80183BB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u8 *func_8012913C(s32 a0);
extern void func_8012B0B4(unsigned int *param_1, int param_2, int param_3);
extern s32 func_8005C49C(void);

void func_80183BB0(s32 a0) {
    s32 p;
    s32 ent;
    s32 t;
    s32 m;
    s32 q;
    register s32 n __asm__("$16");
    unsigned int sp10;

    p = *(s32 *)(a0 + 0x20);                       /* owner's actor */
    *(u16 *)(p + 0x14) = *(u16 *)(p + 0x14) + 0x200;

    *(s32 *)(a0 + 0x1C) = *(s32 *)(a0 + 0x1C) + 1; /* tick counter */
    if ((*(s32 *)(a0 + 0x1C) & 7) != 0) {
        return;
    }
    ent = (s32)func_8012913C(0x6C);                /* alloc particle */
    if (ent == 0) {
        return;
    }
    /* polar scatter: angle in [0,0x1000), radius in [0, actor_r*3/512) */
    func_8012B0B4(&sp10, func_8005C49C() % 0x1000,
                  func_8005C49C() % ((*(s16 *)(*(s32 *)(a0 + 0x20) + 0x18) * 3) >> 9));
    t = (s32)sp10;                                 /* packed dx (lo16) / dz (hi16) */
    *(u16 *)(ent + 6) = *(u16 *)(a0 + 6) + t;      /* X */
    *(u16 *)(ent + 0xA) = *(u16 *)(a0 + 0xA);      /* Y */
    *(u16 *)(ent + 0xE) = *(u16 *)(a0 + 0xE) + (t >> 16); /* Z */

    /* vel X = +/- (func_8005C49C() % 4) << 16 */
    q = func_8005C49C();
    n = q;
    if (q < 0) n = q + 3;
    n = n >> 2;
    n = n << 2;
    m = (q - n) << 16;
    if ((func_8005C49C() & 1) == 0) m = -m;
    *(s32 *)(ent + 0x10) = m;

    /* vel Z = +/- (func_8005C49C() % 4) << 16 */
    q = func_8005C49C();
    n = q;
    if (q < 0) n = q + 3;
    n = n >> 2;
    n = n << 2;
    m = (q - n) << 16;
    if ((func_8005C49C() & 1) == 0) m = -m;
    *(s32 *)(ent + 0x18) = m;

    /* vel Y = (-12 - func_8005C49C() % 9) << 16   (0x38E38E39 magic /9) */
    *(s32 *)(ent + 0x14) = -0xC0000 - ((func_8005C49C() % 9) << 16);
    *(s32 *)(ent + 0x2C) = a0;                     /* owner backref */
}
