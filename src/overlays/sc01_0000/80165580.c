/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165580 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC5;
extern u8 D_80078EC1;
extern void (*D_8018186C[])(s32);
extern void func_80165B28(void *a0);

void func_80165580(s32 _arg0)
{
    if (D_80078EC5 & 0x80) {
        ((void (*)(void))func_80165B28)();
    } else {
        D_8018186C[D_80078EC1 & 0x7F](_arg0);
    }
}
