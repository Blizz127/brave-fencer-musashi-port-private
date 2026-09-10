/* SC02 resident retail span [80169B80,80169BBC). Offset 0x41A28 at base 80128158.
 * SHA256(span)=a8de6014407059a1214908a43b3c2f4fee1333232a42af8625cb0f26caf916b4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181458->D_80187D48.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187D48[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80169B80(T *p) {
    D_80187D48[p->idx](p);
}
