/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D064 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8019FA54;
extern s32 D_8019FA48;
extern void func_8013D9B0();
extern s32 D_8019FA60;
extern s32 D_8019FA64;

void func_8013D064(void)
{
    if (D_8019FA60 != 0) {
        if (D_8019FA60 != 2) {
            if (((D_8019FA60 < 3) && (D_8019FA60 == 1)) &&
                (D_8019FA64 = D_8019FA64 + 1, 0x23a < D_8019FA64)) {
                D_8019FA48 = D_8019FA60;
                D_8019FA60 = 2;
            }
        } else {
            D_8019FA48 = D_8019FA48 + -1;
            if (D_8019FA48 == 0) {
                D_8019FA48 = D_8019FA60;
                ((void (*)(s32))func_8013D9B0)(2);
                if (D_8019FA54 == 0) {
                    D_8019FA60 = D_8019FA60 + 1;
                }
            }
        }
    }
    return;
}
