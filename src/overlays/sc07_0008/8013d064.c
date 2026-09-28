/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013D064 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801953B0;
extern s32 D_80195398;
extern s32 D_801953B4;
extern s32 D_801953A4;
extern void func_8013D9B0();

void func_8013D064(void)
{
    if (D_801953B0 != 0) {
        if (D_801953B0 != 2) {
            if (((D_801953B0 < 3) && (D_801953B0 == 1)) &&
                (D_801953B4 = D_801953B4 + 1, 0x23a < D_801953B4)) {
                D_80195398 = D_801953B0;
                D_801953B0 = 2;
            }
        } else {
            D_80195398 = D_80195398 + -1;
            if (D_80195398 == 0) {
                D_80195398 = D_801953B0;
                ((void (*)(s32))func_8013D9B0)(2);
                if (D_801953A4 == 0) {
                    D_801953B0 = D_801953B0 + 1;
                }
            }
        }
    }
    return;
}
