/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801711FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_801719A4(int a0, int a1);
extern s32 func_80171990(u8 *a0);
extern void func_80171238(void);

void func_801711FC(u8 *param_1) {
    func_801719A4((int)param_1, 1);
    func_80171990(param_1);
    ((void (*)(int))func_80171238)((int)param_1);
}
