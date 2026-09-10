/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E5B8,8016E5F4).
 * Offset 0x46460 at overlay base 80128158. SHA256(span)=4eee1f82c366bccb5331c6122f26d877e8289ef2ad241b665d1266c46a6d69c1.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_8018170C here is D_80181F94 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181F94[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8016E5B8(T *p) {
    D_80181F94[p->idx](p);
}
