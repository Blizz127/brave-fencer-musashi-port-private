/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016C14C,8016C188).
 * Offset 0x43FF4 at overlay base 80128158. SHA256(span)=41ff377da855f5ca6408592c243da87a53f1f309a3632602e018c7b4220492d6.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801815E8 here is D_80181E70 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181E70[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8016C14C(T *p) {
    D_80181E70[p->idx](p);
}
