/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80184274 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

/* m2c compat (vendor/bfm-decomp/include/common.h). */
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))

extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C354(s32 a0, s32 a1);
extern void func_8012A828(s32, void*);
extern s32 func_801788B8(s32 arg0, s32 arg1);
extern void func_80184358(void);

void func_80184274(s32 a0) {

    extern M2C_UNK D_80189450;
    extern u8 D_80184F9C[];
    s32 s0 = a0;
    if (func_8012C354(a0, (s32)&D_80189450)) {
        *(u8 *)(s0 + 0xC0) = 1;
        *(u16 *)(s0 + 0x2) = 1;
        ((void (*)(s32*, s32))func_8012A828)((s32 *)s0, (s32)D_80184F9C);
        func_801788B8(s0, (s32)func_80184358);
    }
}
