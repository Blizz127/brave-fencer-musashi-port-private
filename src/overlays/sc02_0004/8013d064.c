/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D064 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80195024;
extern s32 D_80195018;
extern void func_8013D9B0();
extern s32 D_80195030;
extern s32 D_80195034;

void func_8013D064(void)
{
    if (D_80195030 != 0) {
        if (D_80195030 != 2) {
            if (((D_80195030 < 3) && (D_80195030 == 1)) &&
                (D_80195034 = D_80195034 + 1, 0x23a < D_80195034)) {
                D_80195018 = D_80195030;
                D_80195030 = 2;
            }
        } else {
            D_80195018 = D_80195018 + -1;
            if (D_80195018 == 0) {
                D_80195018 = D_80195030;
                ((void (*)(s32))func_8013D9B0)(2);
                if (D_80195024 == 0) {
                    D_80195030 = D_80195030 + 1;
                }
            }
        }
    }
    return;
}
