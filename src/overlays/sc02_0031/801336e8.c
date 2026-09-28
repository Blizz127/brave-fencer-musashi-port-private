/* Complete retail export [801336E8,8013373C). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801336E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_801B62D8;
extern s32 D_801B62DC[];
extern int D_801B62E0;
extern void func_80136BC4(s32 a0);

void func_801336E8(void *a0, int a1, int a2) {
    if (a0 != 0) {
        (*(void * *)&D_801B62D8) = a0;
        ((void (*)(void))func_80136BC4)();
    }
    (*(int *)&D_801B62DC) = a1;
    D_801B62E0 = a2;
}
