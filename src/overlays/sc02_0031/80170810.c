/* SC02 resident retail span [80170810,8017084C). Offset 0x486B8 at base 80128158.
 * SHA256(span)=88687f5f17fd6fedb41cb8e61eec796f1912880cbb11343ce8ecf57e4b29b0a8.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181890->D_80188180.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80188180[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_80170810(T *p) {
    D_80188180[p->idx](p);
}
