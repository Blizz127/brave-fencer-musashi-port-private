/* SC02.CD FILE_031 / ov_SC02_031 retail span [801714E4,80171520).
 * Offset 0x4938C at overlay base 80128158. SHA256(span)=39a8796c2aeb0dd2100428f108af13ed7cc35f447e1ccf77c4b91937d9af8613.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801818F0 here is D_80182178 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182178[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801714E4(T *p) {
    D_80182178[p->idx](p);
}
