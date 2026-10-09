/* SC02.CD member35 [8017BC38,8017BCA0): twin of main_0012 8017BC38 (src/overlays/main_0012/8017bc38.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801BE87C[10];
void func_8017BC38(void *p) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (D_801BE87C[i])
            D_801BE87C[i](p);
    }
}
