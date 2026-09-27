/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

/* Exact overlay word export for [8017BEBC,8017BEE4) from MAIN.CD
 * member0012 (extracted/overlays/main/0012.bin offset 0x7BD64, base 80128158).
 * Live STOP 8017BEBC: D_8017E354 cell, jal 80016714(801853F0, 8).
 */
#include "psx_types.h"

void func_80016714(void *, s32);                            /* extern */
extern s32 *D_801853F0;

void func_8017BEBC(void) {
    func_80016714(&D_801853F0, 8);
}
