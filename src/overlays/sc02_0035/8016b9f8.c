/* SC02.CD member35 [8016B9F8,8016BA48): twin of main_0012 8016B9F8 (src/overlays/main_0012/8016b9f8.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern s32 D_801BDBA0;
s32 func_8012EFB8();
void func_80015954();
s32 func_8016B9F8(u8 *p) {
    s16 tmp[4];
    s32 v = func_8012EFB8(&D_801BDBA0, tmp);
    func_80015954(tmp, p + 4);
    return (v & ~0x1000) != 0;
}
