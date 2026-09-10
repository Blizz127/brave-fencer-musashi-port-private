/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void func_80029124(s32, s32);                              /* static */
extern s32 D_80078E8C;
extern s16 D_80078EB2;
extern s16 D_80078EB4;
extern s16 D_80078EB6;
extern s16 D_80078EB8;
extern s8 D_80078EC0;

void func_800295D4(void) {
    D_80078EB4 = 0xFA;
    D_80078EB2 = 0xFA;
    D_80078EB8 = 0xFA;
    D_80078EB6 = 0xFA;
    func_80029124(0x1E, 1);
    D_80078EC0 = 1;
    func_80029124(0x80, 1);
    D_80078E8C = 0x64;
    func_80029124(0x82, 1);
    func_80029124(0x83, 1);
    func_80029124(0x85, 1);
}

