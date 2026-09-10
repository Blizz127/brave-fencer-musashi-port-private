/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016DF20,8016DF5C).
 * Offset 0x45DC8 at overlay base 80128158. SHA256(span)=d957224fbf1c93b8eadc8e9dd64bccfcb209d38b15ec2b2ea788fa25cd0925a5.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801816B8 here is D_80181F40 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80181F40[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_8016DF20(T *p) {
    D_80181F40[p->idx](p);
}
