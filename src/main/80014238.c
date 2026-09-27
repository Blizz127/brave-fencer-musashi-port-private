/* Exact retail word export for [80014238,800142C8); EXE and assembly verified. */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void func_800142C8();                                  /* static */
void func_800143AC();                                  /* static */
void func_80014444();                                  /* static */
void func_80014588();                                  /* static */
void func_80014928();                                  /* static */
void func_80015310();                                  /* static */
void func_80016714(void *, s32);                            /* static */
void func_8001C044();                                  /* static */
void func_80028A48();                                  /* static */
void func_80028C50();                                  /* static */
void func_8004239C();                                 /* static */
void func_80059234();                                 /* static */
void func_80059658();                                 /* static */
extern s32 *D_800AF630;

void func_80014238(void) {
    func_80014928();
    func_80059234(1);
    func_80059658(0);
    func_8004239C(0);
    func_80016714(&D_800AF630, 0xA444);
    func_800143AC();
    func_80014444();
    func_8001C044();
    func_80014588();
    func_80015310();
    func_80028A48();
    func_80028C50();
    func_800142C8();
    func_80059658(1);
}
