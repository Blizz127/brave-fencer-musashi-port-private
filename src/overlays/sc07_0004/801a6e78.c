/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6E78 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_8001C214(s32 a0, s32 a1);
extern void func_801A5798(s32);
extern s32 func_80143970(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_801A53F4();
extern u8 D_801BA9E8[];
extern u8 D_801EFA00[];

void func_801A6E78(void *a0) {
    s32 v0;

    v0 = func_8012C1B8();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
    } else {
        func_8001C214(v0, (s32)D_801BA9E8);
        ((void (*)(void *))func_801A5798)(a0);
        *(s32 *)((s32)a0 + 0xD0) = func_80143970((s32)a0);
        func_8012A828((s32)a0, D_801EFA00);
        func_801A53F4(a0);
    }
}
