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

extern s32 D_8019C090;
extern s32 D_8019C078;
extern s32 D_8019C094;
extern s32 D_8019C084;
extern void func_8013D9B0();

void func_8013D064(void)
{
    if (D_8019C090 != 0) {
        if (D_8019C090 != 2) {
            if (((D_8019C090 < 3) && (D_8019C090 == 1)) &&
                (D_8019C094 = D_8019C094 + 1, 0x23a < D_8019C094)) {
                D_8019C078 = D_8019C090;
                D_8019C090 = 2;
            }
        } else {
            D_8019C078 = D_8019C078 + -1;
            if (D_8019C078 == 0) {
                D_8019C078 = D_8019C090;
                ((void (*)(s32))func_8013D9B0)(2);
                if (D_8019C084 == 0) {
                    D_8019C090 = D_8019C090 + 1;
                }
            }
        }
    }
    return;
}
