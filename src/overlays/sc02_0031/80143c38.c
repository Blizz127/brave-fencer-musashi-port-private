/* SC02 resident retail span [80143C38,80143C74). Offset 0x1BAE0 at base 80128158.
 * SHA256(span)=bdd31f7e907e2bd4dbb030c2477e88cbcb76faadbee3f7aabbbea1ac2b682cd9.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017FCB0->D_801865A0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801865A0[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80143C38(T *p) {
    D_801865A0[p->idx](p);
}
