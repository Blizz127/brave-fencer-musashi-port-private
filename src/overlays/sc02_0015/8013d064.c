/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D064 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8018F0FC;
extern s32 D_8018F0F0;
extern void func_8013D9B0();
extern s32 D_8018F108;
extern s32 D_8018F10C;

void func_8013D064(void)
{
    if (D_8018F108 != 0) {
        if (D_8018F108 != 2) {
            if (((D_8018F108 < 3) && (D_8018F108 == 1)) &&
                (D_8018F10C = D_8018F10C + 1, 0x23a < D_8018F10C)) {
                D_8018F0F0 = D_8018F108;
                D_8018F108 = 2;
            }
        } else {
            D_8018F0F0 = D_8018F0F0 + -1;
            if (D_8018F0F0 == 0) {
                D_8018F0F0 = D_8018F108;
                ((void (*)(s32))func_8013D9B0)(2);
                if (D_8018F0FC == 0) {
                    D_8018F108 = D_8018F108 + 1;
                }
            }
        }
    }
    return;
}
