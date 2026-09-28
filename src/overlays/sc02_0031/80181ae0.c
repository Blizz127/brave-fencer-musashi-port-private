/* SC02 resident image [80181AE0,80181B78) at overlay base 0x80128158.
 * SHA256(span)=02934f2d0a59389be8b7e9e32cd8b338bb17f7ae1fbf9b3028749d1069b3136a.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80181AE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80013294(void *a0, void *a1);
extern void func_8012A568(void (*a0)(void));
extern s16 D_80126CB4;

s32 func_80181AE0(void *arg0, s32 arg1) {
    void *p;
    s32 best;
    s32 lim;
    s32 w;
    s32 val;

    best = 0xFFFF;
    p = arg0;
    while (*(s16 *)((u8 *)p + 6) == 0) {
        lim = (s16)arg1;
        w = func_80013294(&D_80126CB4, p);
        val = w & 0xFFFF;
        if (val < lim && (u32)val < (u32)(u16)best) {
            best = w;
        }
        p = (u8 *)p + 8;
    }
    return best & 0xFFFF;
}
