/* SC02.CD member35 [801622C4,80162330): twin of main_0012 801622C4 (src/overlays/main_0012/801622c4.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80029124();
void func_800291C8();
void func_80016714();
extern void *D_801BD788[3];
void func_801622C4(void) {
    s32 i;
    func_80029124(0x141, 1);
    func_800291C8(8, 0);
    for (i = 0; i < 3; i++) {
        func_80016714(D_801BD788[i], 0x38);
    }
}
