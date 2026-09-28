/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A4BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct BigCopy { s32 words[41]; };
extern s32 D_801151D4;
extern struct BigCopy D_80126DB8;
extern struct BigCopy D_80114EE8;
extern u8 D_80127504;

void func_8012A4BC(void) {
    D_80126DB8 = *(struct BigCopy *)D_801151D4;
    *(struct BigCopy *)D_801151D4 = D_80114EE8;
    D_80127504 = 0x30;
}
