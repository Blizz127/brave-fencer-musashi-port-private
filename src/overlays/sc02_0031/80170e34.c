/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170E34,80170E70).
 * Offset 0x48CDC at overlay base 80128158. SHA256(span)=1bde9f4337762cfe0578b9dd82733894790f1763335f86e492146e2b15e716c8.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801818B8 here is D_80182140 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182140[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170E34(T *p) {
    D_80182140[p->idx](p);
}
