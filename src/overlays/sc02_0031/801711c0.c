/* SC02.CD FILE_031 / ov_SC02_031 retail span [801711C0,801711FC).
 * Offset 0x49068 at overlay base 80128158. SHA256(span)=8893063bc262c30432e51faf0166a10f6aff8aa8580a8914fefb52d3ef641489.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801818E0 here is D_80182168 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182168[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801711C0(T *p) {
    D_80182168[p->idx](p);
}
