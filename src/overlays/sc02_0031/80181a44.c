/* SC02 resident image [80181A44,80181AE0) at overlay base 0x80128158.
 * SHA256(span)=a3b6a4cb7346ea1850447cc22d3b4f7ff87fd941fe611094e43e775a366a3803.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80181A44 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_800291B4(s32 arg);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_80181A44(void) {

    extern u16 D_800B99DA;
    extern u16 D_80188DF0[];
    extern s32 func_80181AE0(u16 *a0, s32 a1);
    s32 s0;
    s32 v1;

    if ((D_800B99DA & 3) == 0) {
        if ((func_800291B4(0xCE) & 0xFF) != 0) {
            s0 = 0x537;
        } else {
            s0 = 0x538;
        }

        v1 = func_80181AE0(D_80188DF0, 0x1500) & 0xFFFF;
        if (v1 != 0xFFFF) {
            func_8002D4C8(s0, ((0x7F - v1 / 56) | 0x1000) & 0xFFFF);
        }
    }
}
