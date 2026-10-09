/* SC02.CD member35 [801550FC,80155150): twin of main_0012 801550FC (src/overlays/main_0012/801550fc.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80059A80();
void func_800183E0();
extern u8 D_801862FC[];
void func_801550FC(s32 a0) {
    if (a0 & 0x40000000) {
        func_80059A80(D_801862FC + ((a0 & 0xFF) * 8), 0x200, 0x100);
    } else {
        func_800183E0(a0);
    }
}
