/* SC02.CD member35 [80161D88,80161E08): twin of main_0012 80161D88 (src/overlays/main_0012/80161d88.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
s32 func_80029178();
void func_80029124();
void func_800D1734();
extern s32 D_800AE6B0;
extern s32 D_800AE6A8;
extern s32 D_8018700C;
void func_80161D88(void) {
    if (D_800AE6B0 & 0x80FFFFFF) {
        return;
    }
    if (D_800AE6A8 & 0x80FFFFFF) {
        return;
    }
    if (func_80029178(0x141) & 0xFF) {
        func_80029124(0x141, 0);
        func_80029124(0x95, 1);
        func_800D1734(&D_8018700C);
    }
}
