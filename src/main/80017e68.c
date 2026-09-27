/* Main-exec range [80017E68,80017E8C) from the SLUS executable.
 * SHA256(span)=90acb032f1bd1d3e82722930dd69291ce4b6109cd17178de169b191204b09560.
 * Word export for the native seam; the C body below keeps its
 * own oracle match claim. */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void func_80017E68(s16 *arg0, s32 *arg1) {
    arg1[5] = arg0[0];
    arg1[6] = arg0[1];
    arg1[7] = arg0[2];
}
