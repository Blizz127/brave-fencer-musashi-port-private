/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A0230 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012C354(s32 a0, s32 a1);
extern s32 func_8012C588(s32 a0, s32 a1);
extern s32 func_80143970(s32 a0);
extern void func_80053290(u32 *p);
extern void func_8017D7B0();
extern void func_801A1E94(void);
extern void func_801A3B08(s32 a0);
extern s32 func_801A44C4(s32 a0);
extern void func_801A1E74(s32 a0);
extern s32 D_801AFBE4;
extern s32 D_801F871C;
extern s32 D_801B6E94[0x11];
extern s32 D_801F86D0[0x11];
extern s32 D_801B872C;
extern s32 D_801AFC18[1];
extern u16 D_801F885C;
extern u16 D_801F8718;
extern s16 D_801F8714;

void func_801A0230(s32 a0) {
    s32 v0;
    s32 v1;
    register s32 i __asm__("$4");
    s32 *p;

    if (func_8012C354(a0, (s32) &D_801AFBE4) != 0) {
        v0 = *(s32 *)(a0 + 0x20);
        v1 = *(u16 *)(v0 + 0x2C);
        D_801F871C = a0;
        v1 |= 0x10;
        *(u16 *)(v0 + 0x2C) = v1;
        *(u16 *)(a0 + 0xE) = 0;
        *(u16 *)(a0 + 0x6) = 0;
        *(s16 *)(a0 + 0xA) = -0x240;

        for (i = 0; i < 0x44; i += 4) {
            *(s32 *)((u8 *)D_801F86D0 + i) = *(s32 *)((u8 *)D_801B6E94 + i);
        }

        for (p = &D_801B872C; *p != 0; p++) {
            func_80053290((u32 *)(*p + 4));
        }

        v0 = func_801A44C4(a0);
        *(s32 *)(a0 + 0xD8) = v0;
        func_8012C588(0x3BB, a0);

        v1 = *(s32 *)(a0 + 0xC4);
        D_801F885C = 0;
        *(u8 *)(a0 + 0xC0) = 1;
        *(s16 *)(a0 + 0xAE) = -1;
        *(s32 *)(a0 + 0xB4) = 0;
        *(s32 *)(a0 + 0xBC) = (s32) D_801AFC18;
        *(u8 *)(a0 + 0xC1) = 0;
        v1 |= 2;
        *(s32 *)(a0 + 0xC4) = v1;
        v0 = func_80143970(a0);
        *(s32 *)(a0 + 0xD0) = v0;

        D_801F8718 = 0xC62;
        D_801F8714 = 0xC62;
        func_801A3B08(a0);
        func_8017D7B0();

        if (*(s32 *)(a0 + 0x64) != 0) {
            ((void (*)(s32))func_801A1E94)(a0);
        } else {
            func_801A1E74(a0);
        }
    }
}
