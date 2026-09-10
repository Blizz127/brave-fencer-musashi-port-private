/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157DC4,80157E00).
 * Offset 0x2FC6C at overlay base 80128158. SHA256(span)=3a40dfeadd9c847796eb17f76c8715567d0c66ee7c13cde97ade2a6dbfc2ac74.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801806CC here is D_80180F54 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80180F54[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80157DC4(T *p) {
    D_80180F54[p->idx](p);
}
