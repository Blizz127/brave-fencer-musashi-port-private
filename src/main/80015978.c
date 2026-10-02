/* Complete retail export [80015978,8001599C). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

/* returns arg0[5]: retail leaves that lhu in v0 and callers read v0 after the jal. */
u16 func_80015978(u16 *arg0, u16 *arg1) {
    u16 t;
    arg1[0] = arg0[1];
    arg1[1] = arg0[3];
    t = arg0[5];
    arg1[2] = t;
    return t;
}
