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

extern s32 D_80199868;
extern s32 D_80199850;
extern s32 D_8019986C;
extern s32 D_8019985C;
extern void func_8013D9B0();

void func_8013D064(void)
{
    if (D_80199868 != 0) {
        if (D_80199868 != 2) {
            if (((D_80199868 < 3) && (D_80199868 == 1)) &&
                (D_8019986C = D_8019986C + 1, 0x23a < D_8019986C)) {
                D_80199850 = D_80199868;
                D_80199868 = 2;
            }
        } else {
            D_80199850 = D_80199850 + -1;
            if (D_80199850 == 0) {
                D_80199850 = D_80199868;
                ((void (*)(s32))func_8013D9B0)(2);
                if (D_8019985C == 0) {
                    D_80199868 = D_80199868 + 1;
                }
            }
        }
    }
    return;
}
