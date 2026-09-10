/* SC02 resident retail span [80157FC4,80158000). Offset 0x2FE6C at base 80128158.
 * SHA256(span)=ad7a9b2234e50ec5f47d089f922988667647d092a1991e7c8968583d41e309e6.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801806D4->D_80186FC4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186FC4[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80157FC4(T *p) {
    D_80186FC4[p->idx](p);
}
