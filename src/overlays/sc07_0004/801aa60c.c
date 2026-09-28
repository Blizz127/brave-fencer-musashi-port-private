/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AA60C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800AF648;
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern s32 func_8004955C(s32 a0, s32 a1, s32 *a2, s32 *a3);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_801AA60C(s32 param_1, s32 param_2)
{
    struct { s16 in[3]; s16 pad; s16 xy[2]; s32 p; s32 flag; } f;
    register s32 p1 __asm__("$17");
    register s32 s2 __asm__("$18");
    s16 q;

    p1 = param_1;
    s2 = param_2;
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    f.in[0] = *(s16 *)(p1 + 6);
    f.in[1] = *(s16 *)(p1 + 0xA);
    f.in[2] = *(s16 *)(p1 + 0xE);
    func_8004955C((s32)f.in, (s32)f.xy, &f.p, &f.flag);
    if (f.flag >= 0 && (u16)(f.xy[0] + 0xC8) < 0x191 && (u16)(f.xy[1] + 0xAA) < 0x155) {
        f.xy[0] = f.xy[0] + 0xA0;
        q = (f.xy[0] * 128) / 320;
        if (q <= 0) {
            q = 1;
        }
        if (q >= 128) {
            q = 127;
        }
        func_8002D4C8(s2 & 0xFFFF, (q | 0x2000) & 0xFFFF);
    }
}
