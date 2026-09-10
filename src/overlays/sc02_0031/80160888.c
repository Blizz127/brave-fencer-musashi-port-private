/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160888,801608C0).
 * Offset 0x38730 at overlay base 80128158. SHA256(span)=e20428464f46c22bb67cf65fa42b7fadb3f0db1fbd0f8a82c362579a36fc8f06.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160888.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_801608C0(s32);                               /* static */
s32 func_80161104();                                /* static */

void func_80160888(s32 arg0) {
    if (func_80161104() != 0) {
        func_801608C0(arg0);
    }
}
