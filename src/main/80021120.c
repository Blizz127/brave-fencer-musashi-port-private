/* Main-exec range [80021120,80021174) from the SLUS executable.
 * SHA256(span)=0ace3265e3010f4b4d9f630788d8d2a718878d50d32175b6fe7b96531c402be5.
 * Word export for the native seam; the C body below keeps its
 * own oracle match claim. */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_80053AF8(s16, s16, s16);                     /* static */
extern s16 D_800AE7E0;
extern s16 D_800AE7E2;
extern s16 D_800AE7E4;

void func_80021120(s32 *arg0) {
    func_80053AF8(D_800AE7E0, D_800AE7E2, D_800AE7E4);
    *arg0 += 1;
}
