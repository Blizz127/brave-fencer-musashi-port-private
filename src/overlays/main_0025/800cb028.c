/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB028 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CBBA0(s32 param_1);

void func_800CB028(s32 param_1) {
    *(u16 *)(param_1 + 0xB8) = *(u16 *)(param_1 + 0xBA);
    func_800CBBA0(param_1);
    *(u8 *)(param_1 + 0x197) += 1;
}
