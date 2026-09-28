/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A57E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8001D074(s32 a0, s32 a1);
extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C2C4(s32 a0);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8001CD9C(s32 a0, s32 a1);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern void func_801A5AA0(void *a0);
extern void func_801A5AE0(void *a0);
extern void func_801A5B00();
extern int func_8005C49C(void);
typedef struct { u16 a, b, c, d; } Rec8_801A57E8;
extern Rec8_801A57E8 D_801B0174[];
extern Rec8_801A57E8 D_801AFE44[];
extern u8 D_801AFEBC[];
extern u8 D_801B01C4[];
extern u8 D_801B01EC[];
extern s32 D_801B02B8[];
extern u8 D_801F8744[];

void func_801A57E8(void *a0) {
    s32 s1;
    s32 v0;
    s32 v;

    s1 = func_8001D074(0x7E, 0x100);
    *(s32 *)((s32)a0 + 0xCC) = s1;
    v0 = func_8012C1B8();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0 || s1 == 0) {
        func_8012CAE4(a0);
        return;
    }
    func_8001C2C4(v0);

    if (*(u16 *)((s32)a0 + 0x70) & 0x100) {
        *(s16 *)((s32)a0 + 0x104) = *(u16 *)(*(s32 *)((s32)a0 + 0x64) + 0x36);
    }
    *(s16 *)((s32)a0 + 0x70) = *(u8 *)((s32)a0 + 0x70);

    /* NOTE: 0xD4 is written THIRD in the source but the scheduler sinks/raises
     * it to land between the 0x102 and 0xFE stores, exactly as in the target. */
    if (*(s16 *)((s32)a0 + 0x104) != 0) {
        *(s16 *)((s32)a0 + 0x102) = D_801B0174[*(s16 *)((s32)a0 + 0x70)].d & 0xF000;
        *(s16 *)((s32)a0 + 0xFE) = D_801B0174[*(s16 *)((s32)a0 + 0x70)].d & 0xFFF;
        *(s32 *)((s32)a0 + 0xD4) = (s32)D_801B01C4;
        *(s16 *)((s32)a0 + 0x6) = D_801B0174[*(s16 *)((s32)a0 + 0x70)].a;
        *(s16 *)((s32)a0 + 0xA) = D_801B0174[*(s16 *)((s32)a0 + 0x70)].b;
        *(s16 *)((s32)a0 + 0xE) = D_801B0174[*(s16 *)((s32)a0 + 0x70)].c;
    } else {
        *(s16 *)((s32)a0 + 0x102) = D_801AFE44[*(s16 *)((s32)a0 + 0x70)].d & 0xF000;
        *(s16 *)((s32)a0 + 0xFE) = D_801AFE44[*(s16 *)((s32)a0 + 0x70)].d & 0xFFF;
        *(s32 *)((s32)a0 + 0xD4) = (s32)D_801AFEBC;
        *(s16 *)((s32)a0 + 0x6) = D_801AFE44[*(s16 *)((s32)a0 + 0x70)].a;
        *(s16 *)((s32)a0 + 0xA) = D_801AFE44[*(s16 *)((s32)a0 + 0x70)].b;
        *(s16 *)((s32)a0 + 0xE) = D_801AFE44[*(s16 *)((s32)a0 + 0x70)].c;
    }

    if (*(s16 *)((s32)a0 + 0x102) != 0) {
        func_8001CC3C(s1, (s32)D_801B01EC, 0, 0);
        func_80128EA8(s1, (s32)a0 + 0xF0, D_801B02B8[func_8005C49C() & 3]);
        *(s16 *)((s32)a0 + 0xF4) = (*(s16 *)((s32)a0 + 0xFE) * 3) & 7;
        *(s16 *)(s1 + 0x1A) = 0x2000;
        *(s16 *)(s1 + 0x18) = 0x2000;
        *(s8 *)(s1 + 0x27) = 0x64;
        func_801A5AE0(a0);
        v = 0x8010;
    } else {
        func_8001CD9C(s1, (s32)D_801F8744);
        *(s16 *)((s32)a0 + 0x100) = ((*(s16 *)((s32)a0 + 0xFE) * 3) << 8) & 0xFFF;
        if (*(s16 *)((s32)a0 + 0x104) != 0) {
            func_801A5B00(a0);
        } else {
            func_801A5AA0(a0);
        }
        v = 0xC020;
    }
    *(s16 *)(s1 + 0x2C) = v;
    *(s32 *)(s1 + 0x4) |= 0x50800000;
}
