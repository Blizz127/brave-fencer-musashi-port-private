/* Main-exec range [800595EC,800595FC) from the SLUS executable.
 * SHA256(span)=67da3f1a0dd7ecc0784b707b54a75a0f0e342fcd9be7b624c8dd2dd1c466994c.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

extern u8 D_8007278A;

/* Adjacent leaf helper recovered from retail; 4/4 words match. */
u8 func_800595EC(void) {
    return D_8007278A;
}
