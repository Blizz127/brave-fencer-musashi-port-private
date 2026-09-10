/* SC02.CD FILE_031 / ov_SC02_031 retail span [801702FC,80170338).
 * Offset 0x481A4 at overlay base 80128158. SHA256(span)=fd9fbae801ed722cb4cb17c5532d2a70206f5e55cbdeba3ae53581212de10cc2.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181858 here is D_801820E0 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801820E0[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801702FC(T *p) {
    D_801820E0[p->idx](p);
}
