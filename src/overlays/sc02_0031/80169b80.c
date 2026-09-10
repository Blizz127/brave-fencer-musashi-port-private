/* SC02.CD FILE_031 / ov_SC02_031 retail span [80169B80,80169BBC).
 * Offset 0x41A28 at overlay base 80128158. SHA256(span)=c05d80399a8409b007169fcd11c7dc7699fa6ac299576d3bdfafbfff9891348f.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181458 here is D_80181CE0 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181CE0[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80169B80(T *p) {
    D_80181CE0[p->idx](p);
}
