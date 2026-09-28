/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBA14 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80126C16;

void func_800CBA14(void *a0) {
    *(u16 *)((s32)a0 + 6) = D_80126C16 - 0x28;
}
