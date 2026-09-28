/* Exact retail overlay 0010 export [800CF5D4,800CF628), offset 0x207DC. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CF5D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80127084;
extern u8 D_80078EC0;
extern s32 func_800D0488(s32 arg0);
extern void func_80011CFC(void);

void func_800CF5D4(void) {
    s32 m;

    if (D_80127084 != 0) {
        m = D_80078EC0 & 0x7F;
        if (m == 0 || ((s32 (*)())func_800D0488)(m) != 0) {
            func_80011CFC();
        }
    }
}
