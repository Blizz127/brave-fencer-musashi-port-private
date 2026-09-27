/* SC02 resident retail span [80159968,801599A4). Offset 0x31810 at base 80128158.
 * SHA256(span)=8e0cc23630f0529e24659e906ae32636cd753a9af2d7f81322964c2bcd3bef1b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A10->D_80187300.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187300[];
typedef struct { u8 pad[77]; u8 idx; } T;
void func_80159968(T *p) {
    D_80187300[p->idx](p);
}
