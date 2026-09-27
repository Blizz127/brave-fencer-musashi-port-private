/* SC02.CD FILE_031 / ov_SC02_031 retail span [801657D8,80165840).
 * Offset 0x3D680 at overlay base 80128158. SHA256(span)=0d7fe953fadd4ad06c646fa577c1acfb0d1502da075f41547e958dc43b47a056.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801657d8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_80078E94;
extern s32 D_80078E9C;
extern s32 D_80078EA0;
extern s32 D_80078EA4;
extern s32 D_80078EA8;
extern u8 D_80078EBB;
extern s32 D_80078ECC;
extern s32 D_80078ED0;
extern s32 D_80078ED4;
extern s32 D_80078ED8;
extern s32 D_80078EDC;
extern u8 D_80078EE0;

void func_801657D8(void) {
    D_80078ECC = D_80078E94;
    D_80078ED0 = D_80078E9C;
    D_80078ED4 = D_80078EA0;
    D_80078ED8 = D_80078EA4;
    D_80078EDC = D_80078EA8;
    D_80078EE0 = D_80078EBB;
}
