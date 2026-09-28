/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D064 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801BD6A4;
extern s32 D_801BD698;
extern void func_8013D9B0();
extern s32 D_801BD6B0;
extern s32 D_801BD6B4;

void func_8013D064(void)
{
    if (D_801BD6B0 != 0) {
        if (D_801BD6B0 != 2) {
            if (((D_801BD6B0 < 3) && (D_801BD6B0 == 1)) &&
                (D_801BD6B4 = D_801BD6B4 + 1, 0x23a < D_801BD6B4)) {
                D_801BD698 = D_801BD6B0;
                D_801BD6B0 = 2;
            }
        } else {
            D_801BD698 = D_801BD698 + -1;
            if (D_801BD698 == 0) {
                D_801BD698 = D_801BD6B0;
                ((void (*)(s32))func_8013D9B0)(2);
                if (D_801BD6A4 == 0) {
                    D_801BD6B0 = D_801BD6B0 + 1;
                }
            }
        }
    }
    return;
}
