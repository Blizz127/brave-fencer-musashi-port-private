/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DA90,8015DAC4).
 * Offset 0x35938 at overlay base 80128158. SHA256(span)=5ac3ef6448edcbd5e48b511d0ebdb8b3237c021b81bc61cfd794746c56888bec.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015da90.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015DB6C();
void func_8015DA90(void *p) {
    func_80147078(p, 14);
    func_8015DB6C(p);
}
