/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void *func_8001CFDC(s32, s32);                              /* extern */

/* B28: returns 8001CFDC's record pointer. The retail tail call leaves it in
 * v0 and 80132018/801320D8 use it as the result; byte-identical
 * (rebuilt with gcc-2.7.2-psx -O2). */
void *func_8012C1B8(void) {
    return func_8001CFDC(0x26, 0x85);
}
