/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AE624 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_8012AD50(void *a0);
extern u8 D_801F07E0[];

void func_801AE624(void *a0) {
    register void *s0 __asm__("$16");
    register s32 v0 __asm__("$2");
    s32 p;
    s32 q;
    s32 r;

    s0 = a0;
    v0 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)((s32)s0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(s0);
        return;
    }
    func_8001C810(v0, (s32)D_801F07E0);

    p = *(s32 *)((s32)s0 + 0x20);
    *(s32 *)(p + 4) |= 0x50000000;

    q = *(s32 *)((s32)s0 + 0x20);
    *(u16 *)(q + 0x2C) |= 0x10;

    r = *(s32 *)((s32)s0 + 0x20);
    *(s16 *)(r + 0x18) = *(s16 *)(r + 0x1A) = *(s16 *)(r + 0x1C) = 0x300;

    if (*(s32 *)((s32)s0 + 0x1C) == 0) {
        *(s32 *)((s32)s0 + 0x1C) = 0x18;
    }
    func_8012AD50(s0);
}
