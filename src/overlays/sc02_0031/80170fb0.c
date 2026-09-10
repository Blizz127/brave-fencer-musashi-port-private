/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170FB0,80170FEC).
 * Offset 0x48E58 at overlay base 80128158. SHA256(span)=3f483dd7dedbaa305faa5d046bba2d6fe8a0528ae5e82e636ecc9d984e83ac44.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801818C8 here is D_80182150 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182150[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170FB0(T *p) {
    D_80182150[p->idx](p);
}
