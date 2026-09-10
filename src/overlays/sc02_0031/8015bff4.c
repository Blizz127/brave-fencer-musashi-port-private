/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015BFF4,8015C030).
 * Offset 0x33E9C at overlay base 80128158. SHA256(span)=c76b28c459e9c8dceb8bdba2219b938b9dabff19bbae84bee3b4047f0a1f2a4b.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180B9C here is D_80181424 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181424[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015BFF4(T *p) {
    D_80181424[p->idx](p);
}
