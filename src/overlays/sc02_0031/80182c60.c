/* Complete SC02 retail span [80182C60,80182CF4).
 * SC02 820xx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80182C60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80016714(void *a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012CAE4(void *a0);
extern s32 func_801830EC(s32 a0, s32 a1, s16 a2, s16 a3, s32 a4);

void func_80182C60(s32 param_1) {
    extern u8 D_80188FF0[];
    extern u8 D_80188FFC[];
    s32 v0;

    v0 = func_801830EC(param_1, (s32)D_80188FF0, 0x300, 0x1C0, 0x80);
    *(s32 *)(param_1 + 0xCC) = v0;
    if (v0 == 0) {
        goto fail;
    }
    v0 = func_801830EC(param_1, (s32)D_80188FFC, 0x310, 0x1C0, 0x81);
    *(s32 *)(param_1 + 0xD0) = v0;
    if (v0 == 0) {
        func_80016714((void *)*(s32 *)(param_1 + 0xCC), 0x38);
    fail:
        func_8012CAE4((void *)param_1);
        return;
    }
    *(s16 *)(param_1 + 0x2) = 1;
}
