/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CDBA4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CDBF4();
extern void func_800CDCA8();

void func_800CDBA4(s32 a0) {
    func_800CDBF4();
    ((void (*)(s32))func_800CDCA8)(a0);
}
