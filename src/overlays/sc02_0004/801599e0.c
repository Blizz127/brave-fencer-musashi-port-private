/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801599E0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80159A20();

void func_801599E0(void *a0) {
    func_80159A20(a0);
    *(u8 *)((s32)a0 + 0x4D) += 1;
}
