/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160A74,80160ACC).
 * Offset 0x3891C at overlay base 80128158. SHA256(span)=5ee7b200b8c983f99ede61c328f43344aae17c09c6a32499a6fa2bc2a4272fcb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160a74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_80147078(s32, s32);                            /* static */
void func_80159B70(s32);                               /* static */
void func_80160B00();                                  /* static */
extern u8 D_80078EBF;

void func_80160A74(s32 arg0) {
    if (D_80078EBF == 0x80) {
        func_80160B00();
        return;
    }
    func_80147078(arg0, 0);
    func_80159B70(arg0);
}
