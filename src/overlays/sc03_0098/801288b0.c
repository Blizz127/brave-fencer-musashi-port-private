#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

int func_8001ABBC(s32, s32, void *, s32, s32);               /* extern */
extern s32 D_801C2FE0;
extern s32 *D_800AEFD0;

/* B28: returns func_8001ABBC's result; the retail tail call leaves it in v0,
 * which callers read. Byte-identical (gcc-2.7.2-psx -O2). */
int func_801288B0(void) {
    return func_8001ABBC(0, 0, &D_800AEFD0, D_801C2FE0, 0);
}
