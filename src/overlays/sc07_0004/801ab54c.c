/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AB54C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A8494(void *a0);

void func_801AB54C(void *a0) {
    register s32 v __asm__("$2");
    register s32 c __asm__("$3");
    s32 p;
    s32 frame_pad[4];
    register s32 z __asm__("$0");

    func_801A8494(a0);

    if (*(s32 *)((s32)a0 + 0x1C) != 0) {
        *(s32 *)((s32)a0 + 0x1C) -= 1;
        return;
    }

    p = *(s32 *)((s32)a0 + 0x20);
    v = *(s16 *)(p + 0x18);
    c = v + z;
    if (v < 0x600) {
        v = c + 0x100;
        *(s16 *)(p + 0x18) = v;
    }

    p = *(s32 *)((s32)a0 + 0x20);
    v = *(s16 *)(p + 0x1A);
    c = v + z;
    if (v < 0xA00) {
        v = c + 0x140;
        *(s16 *)(p + 0x1A) = v;
    }

    (void)&frame_pad;
}
