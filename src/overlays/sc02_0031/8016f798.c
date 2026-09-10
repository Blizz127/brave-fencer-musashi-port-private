/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F798,8016F7D4).
 * Offset 0x47640 at overlay base 80128158. SHA256(span)=64c48fb29a8f0ca0d1dda9800f3a0aa4b99d48cd7dfd08f84220388791336987.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801817DC here is D_80182064 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182064[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_8016F798(T *p) {
    D_80182064[p->idx](p);
}
