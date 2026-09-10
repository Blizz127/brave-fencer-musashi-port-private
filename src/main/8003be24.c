#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_8006B0F0;
extern s32 D_8006B0F4;
s32 func_8003B3D0(s32);                             /* static */

s32 func_8003BE24(s32 arg0) {
    if ((arg0 != 0) && (func_8003B3D0(D_8006B0F4) == 0)) {
        D_8006B0F0 = 1;
        return 1;
    }
    D_8006B0F0 = 0;
    return 0;
}

