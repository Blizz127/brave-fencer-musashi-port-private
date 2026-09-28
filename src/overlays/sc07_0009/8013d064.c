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

extern s32 D_801A2A40;
extern s32 D_801A2A28;
extern s32 D_801A2A44;
extern s32 D_801A2A34;
extern void func_8013D9B0();

void func_8013D064(void)
{
    if (D_801A2A40 != 0) {
        if (D_801A2A40 != 2) {
            if (((D_801A2A40 < 3) && (D_801A2A40 == 1)) &&
                (D_801A2A44 = D_801A2A44 + 1, 0x23a < D_801A2A44)) {
                D_801A2A28 = D_801A2A40;
                D_801A2A40 = 2;
            }
        } else {
            D_801A2A28 = D_801A2A28 + -1;
            if (D_801A2A28 == 0) {
                D_801A2A28 = D_801A2A40;
                ((void (*)(s32))func_8013D9B0)(2);
                if (D_801A2A34 == 0) {
                    D_801A2A40 = D_801A2A40 + 1;
                }
            }
        }
    }
    return;
}
