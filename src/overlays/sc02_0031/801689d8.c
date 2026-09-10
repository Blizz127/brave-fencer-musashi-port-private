/* SC02 resident retail span [801689D8,80168A14). Offset 0x40880 at base 80128158.
 * SHA256(span)=c193730bcd193a2471e649c43a16c786bd0c7b4f23c5e8b336004d93660cb1c8.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018137C->D_80187C6C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187C6C[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_801689D8(T *p) {
    D_80187C6C[p->idx](p);
}
