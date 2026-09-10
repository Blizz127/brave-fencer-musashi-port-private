/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151944,80151980).
 * Offset 0x297EC at overlay base 80128158. SHA256(span)=d592566b93587739b95b9a8787f5704736fcd11922735e467fcdad1086a80d1b.
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
extern CB D_80180918[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80151944(T *p) {
    D_80180918[p->idx](p);
}
