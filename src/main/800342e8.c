/* Main-exec range [800342E8,80034314) from the SLUS executable.
 * SHA256(span)=bce14d8781d79b933aa5f3c9ef5f30cd5a87adcfa2c378c5f44835693535e128.
 * Word export for the native seam. */
#include "psx_types.h"

/* func_800342E8 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u16 D_800A46E8[];

void func_800342E8(u8 *a0, s32 a1) {
    u32 t = a1 * 84 + (u32)D_800A46E8;
    *(u8 *)(t + (u32)a0 + 0x3A) = 0;
}
