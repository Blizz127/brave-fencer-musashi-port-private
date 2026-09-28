/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEB0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801599A4(void *a0);
extern s32 func_80165910();
extern void func_801655E4(s32 a0);
extern void func_8016629C(void *a0);

void func_800CAEB0(void *a0) {
    func_801599A4(a0);
    func_800CAF6C(a0);
    if (func_80165910(a0) == 0) {
        func_801655E4((s32)a0);
    }
    func_8016629C(a0);
    *(u8 *)((s32)a0 + 0x197) += 1;
}
