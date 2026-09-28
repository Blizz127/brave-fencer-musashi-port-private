/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014B2D0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern void func_8014B310(void);

void func_8014B2D0(void) {
    ((void (*)(s32 *))func_8014B310)(&D_80126B58);
}
