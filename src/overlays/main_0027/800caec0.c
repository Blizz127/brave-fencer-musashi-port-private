/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEC0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801599A4(void *a0);
extern void func_800CAF5C(s32 *a0);
extern s32 func_80165910(s32 a0);
extern void func_801655E4(s32 a0);

void func_800CAEC0(s32 a0) {
    func_801599A4((void *)a0);
    func_800CAF5C((s32 *)a0);
    if (func_80165910(a0) == 0) {
        func_801655E4(a0);
    }
    *(u8 *)(a0 + 0x197) += 1;
}
