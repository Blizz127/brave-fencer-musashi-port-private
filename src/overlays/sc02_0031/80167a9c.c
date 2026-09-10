/* SC02.CD FILE_031 / ov_SC02_031 retail span [80167A9C,80167AD8).
 * Offset 0x3F944 at overlay base 80128158. SHA256(span)=0af4ddddd689b324f5be87a36dda5f5304c57db1b6ca734636f6feb904bba012.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_8018135C here is D_80181BE4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181BE4[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80167A9C(T *p) {
    D_80181BE4[p->idx](p);
}
