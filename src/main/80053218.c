/* Exact source export; matched C body preserved under #else. */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_80052BEC();                                  /* static */
extern s16 D_800A5E50;
extern s16 D_800A5E52;
extern u32 D_800AE618;
extern s32 D_800AE61C;
extern s32 D_800AE7E8;
extern s32 D_800C6DC8;
extern s32 D_800C73D0;

void func_80053218(void) {
    D_800A5E50 = (s16) ((s32) (D_800AE618 + ((u32) D_800AE618 >> 0x1F)) >> 1);
    D_800A5E52 = (s16) ((s32) D_800AE61C / 2);
    func_80052BEC();
    D_800C73D0 = 0xA;
    D_800C6DC8 = 0;
    D_800AE7E8 = 0x3FFF;
}
