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

extern s32 D_801EC780;
extern s32 D_801EC768;
extern s32 D_801EC784;
extern s32 D_801EC774;
extern void func_8013D9B0();

void func_8013D064(void)
{
    if (D_801EC780 != 0) {
        if (D_801EC780 != 2) {
            if (((D_801EC780 < 3) && (D_801EC780 == 1)) &&
                (D_801EC784 = D_801EC784 + 1, 0x23a < D_801EC784)) {
                D_801EC768 = D_801EC780;
                D_801EC780 = 2;
            }
        } else {
            D_801EC768 = D_801EC768 + -1;
            if (D_801EC768 == 0) {
                D_801EC768 = D_801EC780;
                ((void (*)(s32))func_8013D9B0)(2);
                if (D_801EC774 == 0) {
                    D_801EC780 = D_801EC780 + 1;
                }
            }
        }
    }
    return;
}
