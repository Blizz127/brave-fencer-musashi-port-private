/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157D74,80157DC4).
 * Offset 0x2FC1C at overlay base 80128158. SHA256(span)=2f828a1a72fe75d1fd601033659c01c964f0890366f5962fbfd130e43561dfca.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157d74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_80157DC4();                                  /* static */
void func_80157FC4();                                  /* static */

void func_80157D74(u16 *arg0) {
    u16 temp_v1;

    temp_v1 = *arg0;
    switch (temp_v1) {                              /* irregular */
    case 36:
        func_80157DC4();
        return;
    case 37:
        func_80157FC4();
        return;
    }
}
