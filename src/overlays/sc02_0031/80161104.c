/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161104,80161124).
 * Offset 0x38FAC at overlay base 80128158. SHA256(span)=7046ecba49d62ff352a4b456a1b45c283d26153d0bb78fa1fec1a990b1d0e97f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161104.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

s32 func_80161208();                                /* static */

s32 func_80161104(void) {
    return func_80161208() == 0;
}
