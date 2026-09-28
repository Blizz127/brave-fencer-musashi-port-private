/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013E588 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_800D0EC4(void);
extern void func_80141874(void);
extern u8 D_800B9A15;
extern unsigned char D_800B9A13;
extern u16 D_80115110;
extern unsigned short D_80115112;
extern void *D_8011DB24;

void func_8013E588(void * _arg0)
{
    if (func_800D0EC4() == 0) {
        D_800B9A15 = 1;
        D_800B9A13 = 2;
        D_80115110 = 1;
        D_80115112 = 0;
        D_8011DB24 = func_80141874;
    }
}
