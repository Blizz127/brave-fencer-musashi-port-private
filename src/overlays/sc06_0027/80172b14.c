/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172B14 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s16 D_80126B32;
extern s32 func_80172B44();
extern void func_80174684(void *);

void func_80172B14(s16 a0) {
    D_80126B32 = a0;
    func_80174684((void *)func_80172B44);
}
