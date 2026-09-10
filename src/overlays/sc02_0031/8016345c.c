/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016345C,801634D8).
 * Offset 0x3B304 at overlay base 80128158. SHA256(span)=ae10026f27ca6558da71ae1bbf1694280de1ad727a863cb2a13c4590f86e40df.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016345c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_80156370(s32);                             /* static */
void func_80163534(s32, s32, s32, s32, s32, s32);        /* static */

void func_8016345C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_s2;

    temp_s2 = arg1 & 0xFFFF;
    func_80163534(arg0, temp_s2, func_80156370(temp_s2) & 0xFFFF, arg2, arg3 & 0xFFFF, arg4);
}
