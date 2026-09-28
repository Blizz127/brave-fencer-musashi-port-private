/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014B2A8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern void func_8014B2F8(void);

void func_8014B2A8(void) {
    ((void (*)(s32 *))func_8014B2F8)(&D_80126B58);
}
