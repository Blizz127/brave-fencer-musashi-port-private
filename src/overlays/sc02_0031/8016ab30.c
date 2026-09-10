/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016AB30,8016AB6C).
 * Offset 0x429D8 at overlay base 80128158. SHA256(span)=451ba5a93b51eb9af8fd551a31553dd9c7762c61eac56a2941972e588ce47372.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801814EC here is D_80181D74 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181D74[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8016AB30(T *p) {
    D_80181D74[p->idx](p);
}
