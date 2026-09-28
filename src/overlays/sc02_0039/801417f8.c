/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801417F8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_800B9A02;
extern short D_800B9A02;
extern u8 D_800B9A15;
extern unsigned short D_80115112;
extern u16 D_80115112;
extern void func_800D2624(void);
extern unsigned short D_80115114;
extern u8 D_800B9A16;
extern u16 D_80115114;

void func_801417F8(void) {
    if (D_800B9A15 == 0 || D_800B9A16 != 0) {
        if (D_80115114 == (u16)(D_800B9A02 ^ 1)) {
            func_800D2624();
        } else {
            D_80115112 += 1;
        }
    }
}
