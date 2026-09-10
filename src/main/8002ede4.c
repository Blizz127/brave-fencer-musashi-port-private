/* Exact retail word export for [8002EDE4,8002EE64); EXE and assembly verified. */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_8002EC10();                                  /* static */
void func_8002EE90();                                  /* static */
void func_80031CC8();                                  /* static */
void func_800385C0(s16);                               /* static */
extern s16 D_800A4E9A;
extern u16 D_800A4EA2;
extern u8 D_800A4EE6;
extern s16 D_800A4EF6;

void func_8002EDE4(void) {
    func_8002EE90();
    func_80031CC8();
    func_8002EC10();
    if (D_800A4EA2 & 4) {
        func_800385C0(D_800A4E9A);
        D_800A4EA2 = 0;
    }
    D_800A4EF6 = 1;
    D_800A4EE6 &= 0xF9;
}
