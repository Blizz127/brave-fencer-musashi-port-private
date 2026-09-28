/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E8440 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801847BC(void *a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012E8E0(s32 a0, s32 a1);
extern s32 func_80178B18(s32 param_1, s32 param_2);
extern s32 D_801E856C;
extern s32 D_801BA288;
extern s32 D_801E8564;
extern s32 D_801E85EC;

void func_801E8440(void *param_1) {
    if (func_801847BC(param_1, &D_801E856C) != 0) {
        *(u16 *)((s32)param_1 + 2) = 1;
        func_8012A828((s32)param_1, &D_801BA288);
        func_8012E8E0((s32)param_1, (s32)&D_801E8564);
        *(u16 *)((s32)param_1 + 0x34) = 0;
        func_80178B18((s32)param_1, (s32)&D_801E85EC);
    }
}
