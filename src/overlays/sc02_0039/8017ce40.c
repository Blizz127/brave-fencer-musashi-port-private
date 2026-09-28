/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017CE40 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8017CFF4(void);

s32 func_8017CE40(s32 a0) {
    func_8017CFF4();
    *(s32 *)(a0 + 0x28) = 10;
    *(u8 *)(a0 + 0x15) += 1;
    return 0;
}
