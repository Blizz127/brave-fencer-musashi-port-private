#include "psx_types.h"

/* Exact matched entry stream for the bounded native MIPS diagnostic. */

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_800142C8();                                  /* static */
void func_80016714(void *, s32);                            /* static */
void func_80059234();                                 /* static */
void func_800594CC();                                 /* static */
void func_80059658();                                 /* static */
extern s32 D_800BA118;

void func_800141F0(void) {
    func_80059234(0);
    func_800594CC(0);
    func_80059658(0);
    func_80016714(&D_800BA118, 0x98);
    func_800142C8();
}
