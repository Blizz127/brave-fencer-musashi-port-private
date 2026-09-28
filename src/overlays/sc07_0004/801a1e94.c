/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1E94 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8001C924(s32 a0, void *a1);
extern void func_80132288(s32 *arg_a0, s32 *a1, s32 a2);
extern s32 func_801A8528(s32 a0);
extern void func_80178B18(s32 a0, s32 a1);
extern void func_8012AD44(s32 *a0, s16 a1);
extern s32 D_801BF01C;
extern s32 D_801F8724;
extern s32 D_801AFB58;
extern s32 D_801AFCF8;

void func_801A1E94(void)
{
    register s32 param_1 __asm__("$4");
    s32 p;
    s32 *s0;
    s32 *s1;

    p = param_1;
    s0 = (s32 *)p;
    s1 = &D_801BF01C;
    func_8001C924(*(s32 *)(p + 0x20), s1);
    func_80132288(&D_801F8724, &D_801AFB58, *s1);
    *(s16 *)(p + 0xA) = -0x240;
    *(s16 *)(p + 0xE) = 0x30;
    *(s32 *)(p + 0xD4) = func_801A8528(p);
    func_80178B18(p, (s32)&D_801AFCF8);
    *(s32 *)(p + 0x1C) = 0x60;
    *(s16 *)(p + 0x100) = 0xFF;
    *(s16 *)(p + 0x84) = 0;
    func_8012AD44((s32 *)p, 0xE);
}
