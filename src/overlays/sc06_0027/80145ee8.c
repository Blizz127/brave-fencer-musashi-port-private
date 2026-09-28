/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80145EE8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029178(s32 arg);
extern void func_80146014(s32 a0);
extern unsigned char D_8017F994[];
extern unsigned char D_8017F9C4[];
extern unsigned char D_8017FA14[];
extern unsigned char D_8017FA44[];
extern unsigned char D_8017FA74[];

void func_80145EE8(s32 param_1)
{
    switch (param_1) {
    case 0:
        if (((unsigned char (*)(int))func_80029178)(0x1F) != 0) {
            ((void (*)(void *))func_80146014)(D_8017F994);
        }
        if (((unsigned char (*)(int))func_80029178)(0x21) != 0) {
            ((void (*)(void *))func_80146014)(D_8017F9C4);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1E) != 0) {
            ((void (*)(void *))func_80146014)(D_8017FA14);
        }
        if (((unsigned char (*)(int))func_80029178)(0x1D) != 0) {
            ((void (*)(void *))func_80146014)(D_8017FA44);
        }
        if (((unsigned char (*)(int))func_80029178)(0x20) == 0) {
            return;
        }
        ((void (*)(void *))func_80146014)(D_8017FA74);
        break;
    case 1:
        ((void (*)(void *))func_80146014)(D_8017F994);
        ((void (*)(void *))func_80146014)(D_8017F9C4);
        ((void (*)(void *))func_80146014)(D_8017FA14);
        ((void (*)(void *))func_80146014)(D_8017FA44);
        ((void (*)(void *))func_80146014)(D_8017FA74);
        break;
    }
}
