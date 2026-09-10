/* SC02 resident retail span [801703E0,8017041C). Offset 0x48288 at base 80128158.
 * SHA256(span)=d30cf315dd455aa9a10fbb2ad0f30d46e0d4f632baa8f225a9c073ce8b3e8099.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181860->D_80188150.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188150[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801703E0(T *p) {
    D_80188150[p->idx](p);
}
