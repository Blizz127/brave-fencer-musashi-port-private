#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_80047CB4();                                  /* static */
void func_8004921C(s32, s32);                              /* static */
void func_80053AD8(s32, s32, s32);                           /* static */
extern s16 D_800A6548;
extern s16 D_800A654A;

void func_80053CF8(void) {
    func_80047CB4();
    func_80053AD8(0, 0, 0);
    func_8004921C(0, 0);
    D_800A654A = 0;
    D_800A6548 = 0;
}
