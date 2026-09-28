/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEE0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80165910(void);
extern void func_801655E4(s32 a0);
extern void func_800CAF64(s32 a0);

void func_800CAEE0(void *a0) {
    if (func_80165910() == 0) {
        func_801655E4((s32) a0);
    }
    func_800CAF64((s32) a0);
    *(u8 *)((s32) a0 + 0x197) += 1;
}
