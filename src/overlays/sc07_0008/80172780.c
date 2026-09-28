/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172780 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S8_80172780 { s16 m[4]; };
extern void func_8012A568(void (*a0)(void));
extern void func_80174684(void *);
extern s16 D_80126B30;
extern s32 func_801727D0();

void func_80172780(void *a0) {
    *(struct S8_80172780 *)&D_80126B30 = *(struct S8_80172780 *)a0;
    func_80174684((void *)func_801727D0);
}
