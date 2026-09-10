/* SC02 resident retail span [801728E4,80172920). Offset 0x4A78C at base 80128158.
 * SHA256(span)=5d1196aa0f4e881c0b269ddcb06e97c6897cf081a84aa0465918c197f07da031.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018190C->D_801881FC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801881FC[];
typedef struct { u8 pad[532]; u8 idx; } T;
void func_801728E4(T *p) {
    D_801881FC[p->idx](p);
}
