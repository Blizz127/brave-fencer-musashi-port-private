/* SC02 resident retail span [8015A264,8015A2A0). Offset 0x3210C at base 80128158.
 * SHA256(span)=8b69fc6d8a7d9950fc0bf8b205fb8d9617e3840474d7f615ee60c5df6bd4a7bf.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180B6C->D_8018745C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018745C[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015A264(T *p) {
    D_8018745C[p->idx](p);
}
