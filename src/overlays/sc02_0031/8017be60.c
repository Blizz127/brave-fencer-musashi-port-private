/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017BE60,8017BE9C).
 * Offset 0x53D08 at overlay base 80128158. SHA256(span)=aff55877d3e71e9a5f312110603b74053d35e6a35f963279bae7f7a57394d48c.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181D60 here is D_801825E8 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801825E8[];
typedef struct { u8 pad[4]; u8 idx; } T;
void func_8017BE60(T *p) {
    D_801825E8[p->idx](p);
}
