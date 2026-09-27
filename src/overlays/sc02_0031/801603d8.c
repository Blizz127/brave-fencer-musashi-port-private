/* SC02.CD FILE_031 / ov_SC02_031 retail span [801603D8,80160410).
 * Offset 0x38280 at overlay base 80128158. SHA256(span)=a2eecd0aa21202e91facd390a8ced71921301c4a69b328836efbeb4759522d06.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801603d8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80160410(s32);                               /* static */
s32 func_80161104();                                /* static */

void func_801603D8(s32 arg0) {
    if (func_80161104() != 0) {
        func_80160410(arg0);
    }
}
