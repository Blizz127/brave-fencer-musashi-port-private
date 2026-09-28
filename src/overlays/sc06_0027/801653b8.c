/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801653B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801653F4(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80165580(s32 _arg0);

void func_801653B8(s32 *a0) {
        s32 s = (s32)a0;
        ((void (*)(s32 *))func_801653F4)((s32 *)s);
        ((void (*)(s32, s32))func_80147078)(s, 0x17);
        ((void (*)(void *))func_80165580)((void *)s);
    }
