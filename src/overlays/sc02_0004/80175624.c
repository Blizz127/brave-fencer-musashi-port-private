/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80175624 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_800B9A02;
extern void func_801757A0(s32);
extern void func_801757A0(s32 a0);
extern short D_800B9A02;

void func_80175624(void *a0) {
    func_801757A0(D_800B9A02);
    *((u8 *)a0 + 1) = *((u8 *)a0 + 1) + 1;
}
