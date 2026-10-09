/* SC02.CD member35 [8016BFA8,8016BFD0): twin of main_0012 8016BFA8 (src/overlays/main_0012/8016bfa8.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_8016BFD0();
extern s32 D_801BDC68;
void func_8016BFA8(void *a0, void *a1, void *a2, void *a3) {
    func_8016BFD0(a0, a1, a2, a3, &D_801BDC68);
}
