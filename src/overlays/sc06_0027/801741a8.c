/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801741A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014BDC8(void);
extern void func_8014BB0C(void);
extern void func_8014B2A8(void);
extern s32 D_80078ED8;
extern s32 D_80078EA4;

void func_801741A8(s32 _arg0)
{
    func_8014BDC8();
    func_8014BB0C();
    func_8014B2A8();
    D_80078ED8 = 0xA00000;
    D_80078EA4 = 0xA00000;
}
