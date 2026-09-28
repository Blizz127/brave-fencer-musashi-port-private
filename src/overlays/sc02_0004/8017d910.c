/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D910 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8017D9C4(void *a0);

void func_8017D910(void *a0) {
    s32 var_s0;
    for (var_s0 = 0; var_s0 < *(s32 *)((s32)a0 + 0x1c); var_s0++) {
        func_8017D9C4(a0);
    }
    func_8017D9C4(a0);
    func_8017D9C4(a0);
    *(s32 *)((s32)a0 + 0x1c) = *(s32 *)((s32)a0 + 0x1c) >> 1;
    if (*(s32 *)((s32)a0 + 0x1c) == 0) {
        *(u16 *)((s32)a0 + 2) += 1;
    }
}
