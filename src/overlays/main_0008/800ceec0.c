/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CEEC0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_800CF13C;
extern void func_800167B8(s32);
extern void func_800118AC(void);
extern s32 func_800149E0(s32);

void func_800CEEC0(void) {
    s32 ret = func_800149E0(0);
    D_800CF13C++;
    if (D_800CF13C >= 0x12D || (ret & 0x8F0)) {
        func_800167B8(4);
        func_800118AC();
    }
}
