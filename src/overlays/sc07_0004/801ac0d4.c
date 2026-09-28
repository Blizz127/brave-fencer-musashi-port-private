/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AC0D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern s32 func_8012BEE8(s32 a0);
extern void func_80016714(void *a0, s32 a1);
extern void func_8012C218(void *a0);

void func_801AC0D4(void *arg0) {
    void *s0;
    s16 val;

    s0 = *(void **)((char *)arg0 + 0xCC);
    func_80128ED8((s32)s0, (s32 *)((char *)arg0 + 0xF0));

    val = *(s16 *)((char *)s0 + 0x1A);
    if (val >= 0x1801) {
        *(s16 *)((char *)s0 + 0x1A) = val - 0x400;
    }

    if (func_8012BEE8((s32)arg0) != 0) {
        func_80016714(*(void **)((char *)arg0 + 0xCC), 0x38);
        func_8012C218(arg0);
    }
}
