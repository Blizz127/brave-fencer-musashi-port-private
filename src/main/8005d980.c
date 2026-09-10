/* Exact retail word export for [8005D980,8005D9C4); EXE and assembly verified. */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_8005CF08();                                  /* static */
void func_8005CF18();                                  /* static */
void func_8005CF58(s32, s32);                              /* static */
void func_8005E178(s32, void *);                            /* static */
extern s32 D_80078988;

void func_8005D980(void) {
    func_8005CF08();
    func_8005CF58(3, 1);
    func_8005E178(2, &D_80078988);
    func_8005CF18();
}
