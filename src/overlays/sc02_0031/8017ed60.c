/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017ED60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern int func_8005C49C(void);
extern s32 func_8012B6D4(s16 *a0, s16 *a1);

void func_8017ED60(s16 *a0) {

    extern u8 D_80126B5C;
    extern s16 D_801B7828;
    extern s32 D_801B7834;
    extern s32 D_801B783C;
    extern u8 D_80188B50[];
    extern s16 D_80188B70[];
    extern s16 D_80188B72[];
    /* The target frame is 0x28 with only $s0/$s1/$ra saved at 0x18/0x1C/0x20, i.e. 8 bytes
       of locals sit below the register save area and are never touched. The original source
       declared a local it no longer uses; the same fossil is visible in the neighbours
       (func_8017C594 carries 16 such bytes). gcc-2.7.2 still reserves the slot. */
    s32 sp10[2];
    s32 a, b, t, r, off, x, y;

    a = (func_8012B6D4((s16 *)&D_80126B5C, &D_801B7828) >> 7) & 0x18;
    b = func_8012B6D4(a0 + 2, &D_801B7828);
    t = a | ((b >> 9) & 7);
    off = D_80188B50[t] << 2;
    r = func_8005C49C();

    /* The struct reads are plain INDIRECT_REFs, not ARRAY_REFs: an `a0[0x46]` here sets
       MEM_IN_STRUCT_P, which lets gcc-2.7.2's true_dependence() drop the dependence against
       the constant-address store and hoist the second `lh` above `sw D_801B7834`. */
    x = *(s16 *)((s32)a0 + 0x88) + *(s16 *)((u8 *)D_80188B70 + off) - 0x100;
    x += (r & 0x7F) << 2;
    D_801B7834 = x << 16;

    y = *(s16 *)((s32)a0 + 0x8C) + *(s16 *)((u8 *)D_80188B72 + off) - 0x100;
    y += (unsigned)(r & 0x7F00) >> 6;
    D_801B783C = y << 16;
}
