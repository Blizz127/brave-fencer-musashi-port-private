/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FB7C,8016FBB8).
 * Offset 0x47A24 at overlay base 80128158. SHA256(span)=70770b72809b6699ebc15a79a0f1ae4c988424de0b4d837d66320f96578780ba.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181808 here is D_80182090 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182090[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_8016FB7C(T *p) {
    D_80182090[p->idx](p);
}
