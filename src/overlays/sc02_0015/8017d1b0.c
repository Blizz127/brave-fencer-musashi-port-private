/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D1B0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800167B8(s32 a0);
extern void func_8017D418(void);

s32 func_8017D1B0(s32 a0) {
    func_8017D418();
    func_800167B8(0);
    *(u8 *)(a0 + 0x15) += 1;
    return 0;
}
