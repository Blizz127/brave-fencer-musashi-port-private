/* SC02.CD FILE_031 / ov_SC02_031 retail span [80175184,801751D8).
 * Offset 0x4D02C at overlay base 80128158. SHA256(span)=e4980926fdd5d4a4d5b19aa1a10e736556c72befe1c58f9c869ba139035d4119.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181A08 here is D_80182290 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182290[];
void func_80175268();
void func_80175184(u16 *p) {
    u16 idx = p[1];
    if (idx < 2)
        D_80182290[idx]();
    else
        func_80175268();
}
