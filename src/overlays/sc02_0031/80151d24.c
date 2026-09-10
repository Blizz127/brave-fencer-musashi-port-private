/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151D24,80151D60).
 * Offset 0x29BCC at overlay base 80128158. SHA256(span)=e86e5c20c0844b486bbc28bb02a66ef506f4621b1d4f7d0c387d0ed5c08869d2.
 * Differs from the registry-verified MAIN member 0012 carve in one data
 * reference only: the member-0012 block is 0x888 lower, so the symbol
 * moved from D_80180000..D_80180887 to +0x888. Oracle MATCH re-earned
 * against the SC02 blob; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80180928[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80151D24(T *p) {
    D_80180928[p->idx](p);
}
