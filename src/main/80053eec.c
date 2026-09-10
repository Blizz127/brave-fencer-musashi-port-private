/* Exact retail word export for [80053EEC,80053F6C); EXE and assembly verified. */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s16 D_800794E0;
extern s16 D_800794E2;
extern s16 D_800794E4;
extern s16 D_800794E6;
extern s16 D_800A4F3C;
extern s16 D_800A4F3E;
extern s16 D_800A4F40;
extern s16 D_800A4F42;
extern s16 D_800C7C88;

void func_80053EEC(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_800794E0 = arg0;
    D_800794E2 = arg2;
    D_800794E4 = arg1;
    D_800794E6 = arg3;
    if (D_800C7C88 != 0) {
        D_800A4F3C = 0;
        D_800A4F3E = 0;
        D_800A4F40 = 0;
        D_800A4F42 = 0;
        return;
    }
    D_800A4F3C = arg0;
    D_800A4F3E = arg2;
    D_800A4F40 = arg1;
    D_800A4F42 = arg3;
}
