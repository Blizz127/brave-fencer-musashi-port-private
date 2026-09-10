/* SC02.CD FILE_031 / ov_SC02_031 retail span [801751D8,80175218).
 * Offset 0x4D080 at overlay base 80128158. SHA256(span)=c7299c34290a64424211de5f31d3a0b936fb5c36b5cc50cc00c5359bc4b85e66.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801751d8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80146CA0(s32);                               /* static */
s32 func_80161104();                                /* static */
void func_80175218(s32);                               /* static */

void func_801751D8(s32 arg0) {
    if (func_80161104() != 0) {
        func_80175218(arg0);
        func_80146CA0(arg0);
    }
}
