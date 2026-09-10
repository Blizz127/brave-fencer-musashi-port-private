/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170AD8,80170B14).
 * Offset 0x48980 at overlay base 80128158. SHA256(span)=d36e22cd9466329340f26b509f9f1e8ef5da2b61f993eb18448582cedd90fbba.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80181898 here is D_80182120 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182120[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170AD8(T *p) {
    D_80182120[p->idx](p);
}
