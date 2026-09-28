/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF10 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);

void func_800CAF10(void *arg0) {
    func_801466F0(0xB, (s32)arg0, 0, 0, 0, 0, 0, 0);
    *(u8 *)((s32)arg0 + 0xBE) = 0;
    *(u8 *)((s32)arg0 + 0x197) += 1;
}
