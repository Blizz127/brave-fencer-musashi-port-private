/* SC02.CD FILE_031 / ov_SC02_031 retail span [80164EA4,80164EE0).
 * Offset 0x3CD4C at overlay base 80128158. SHA256(span)=7842ac3a1d29a26d2ea87f011d62da2929cd6f05b01c7478452db4b277ddc450.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180FA0 here is D_80181828 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181828[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80164EA4(T *p) {
    D_80181828[p->idx](p);
}
