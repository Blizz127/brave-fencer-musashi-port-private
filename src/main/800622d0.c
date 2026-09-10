#include "psx_types.h"


/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_8005CF08();                                  /* static */
void func_8005CF18();                                  /* static */
void func_8005CF48();                                 /* static */
s32 func_80062394();                                /* static */
void func_800627D8(s32);                               /* static */

void func_800622D0(s32 arg0) {
    s32 var_s0;

    var_s0 = arg0;
    func_8005CF48(0);
    func_8005CF08();
    if (func_80062394() == 0) {
        var_s0 = 0;
    }
    func_800627D8(var_s0);
    func_8005CF18();
}
