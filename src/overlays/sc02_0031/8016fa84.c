/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FA84,8016FAC0).
 * Offset 0x4792C at overlay base 80128158. SHA256(span)=7742d8d75d99ccf2645810dc9813c8a6beb3f5eb0fe3be97baf9993970bd3077.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801817FC here is D_80182084 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182084[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_8016FA84(T *p) {
    D_80182084[p->idx](p);
}
