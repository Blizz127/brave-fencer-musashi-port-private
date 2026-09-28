/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE2C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801844BC(void *a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012E8E0(s32 a0, s32 a1);
extern s32 func_80178B18(s32 a0, s32 a1);

void func_801EE2C8(void *param_1) {

    extern s32 D_801EE3F4;
    extern s32 D_801BA244;
    extern s32 D_801EE3EC;
    extern s32 D_801EE474;

    if (func_801844BC(param_1, &D_801EE3F4) != 0) {
        *(s16 *)((s32)param_1 + 0x2) = 1;
        func_8012A828((s32)param_1, &D_801BA244);
        func_8012E8E0((s32)param_1, (s32)&D_801EE3EC);
        *(s16 *)((s32)param_1 + 0x34) = 0;
        func_80178B18((s32)param_1, (s32)&D_801EE474);
    }
}
