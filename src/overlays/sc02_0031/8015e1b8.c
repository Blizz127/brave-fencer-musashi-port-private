/* SC02 resident retail span [8015E1B8,8015E1F4). Offset 0x36060 at base 80128158.
 * SHA256(span)=144ab3ed32c971b2bca68654f52f75b8a6fe8ac1e591dd6dea4a277962940ebb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180CD4->D_801875C4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801875C4[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8015E1B8(T *p) {
    D_801875C4[p->idx](p);
}
