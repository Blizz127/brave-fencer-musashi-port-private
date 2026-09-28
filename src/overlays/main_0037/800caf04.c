/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF04 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80161104(void);
extern void func_800CAF4C(u8 *a0);

void func_800CAF04(u8 *a0) {
    if (func_80161104()) {
        func_800CAF4C(a0);
        *(u8 *)(a0 + 0x197) = *(u8 *)(a0 + 0x197) + 1;
    }
}
