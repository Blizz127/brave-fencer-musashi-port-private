/* Native retail instruction export [8005283C,80052AA0).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s8 D_80078813;
extern s8 D_80078817;
extern s8 D_80078823;
extern s8 D_80078827;
extern s16 D_800A4F3C;
extern s16 D_800A4F3E;
extern s16 D_800A4F40;
extern s16 D_800A4F42;
extern s16 D_800A5E50;
extern s16 D_800A5E52;
extern s32 *D_800A63F0;
extern s16 D_800A63F8;
extern s16 D_800A6400;
extern s32 *D_800A6558;
extern s32 D_800AE618;
extern s32 D_800AE61C;
extern s32 *D_800AE620;
extern s16 D_800AE622;
extern s16 D_800AE624;
extern s16 D_800AE626;
extern s16 D_800AE628;
extern s16 D_800AE62A;
extern s16 D_800AE62C;
extern s16 D_800AE62E;
extern s16 D_800AE630;
extern s32 D_800AE634;
extern s32 D_800AE638;
extern s32 D_800AE63C;
extern s32 *D_800AE7F0;
extern s16 D_800AE7F8;
extern s16 D_800AE820;
extern s16 D_800AE822;
extern s16 D_800AE824;
extern s16 D_800AE826;
extern s32 D_800C7C70;

void func_8005283C(s32 arg0, s32 arg1) {
    D_800AE61C = arg1 & 0xFFFF;
    D_800AE618 = arg0 & 0xFFFF;
    D_800AE624 = 0;
    D_800AE622 = 0;
    D_800AE62A = 0;
    D_800AE626 = 0;
    D_800AE62E = 0;
    D_800AE62C = 0;
    D_800AE63C = 0;
    D_800AE638 = 0;
    D_800AE634 = 0;
    M2C_FIELD(&D_800AE620, s16 *, 0) = 0x1000;
    D_800AE628 = 0x1000;
    D_800AE630 = 0x1000;
    M2C_FIELD(&D_800AE7F0, s32 *, 0) = (s32) M2C_FIELD(&D_800AE620, s16 *, 0);
    M2C_FIELD(&D_800AE7F0, s32 *, 4) = (s32) M2C_FIELD(&D_800AE620, s32 *, 4);
    M2C_FIELD(&D_800AE7F0, s32 *, 8) = (s32) M2C_FIELD(&D_800AE620, s32 *, 8);
    M2C_FIELD(&D_800AE7F0, s32 *, 0xC) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0xC);
    M2C_FIELD(&D_800AE7F0, s32 *, 0x10) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0x10);
    M2C_FIELD(&D_800AE7F0, s32 *, 0x14) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0x14);
    M2C_FIELD(&D_800AE7F0, s32 *, 0x18) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0x18);
    M2C_FIELD(&D_800AE7F0, s32 *, 0x1C) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0x1C);
    M2C_FIELD(&D_800A63F0, s32 *, 0) = (s32) M2C_FIELD(&D_800AE620, s16 *, 0);
    M2C_FIELD(&D_800A63F0, s32 *, 4) = (s32) M2C_FIELD(&D_800AE620, s32 *, 4);
    M2C_FIELD(&D_800A63F0, s32 *, 8) = (s32) M2C_FIELD(&D_800AE620, s32 *, 8);
    M2C_FIELD(&D_800A63F0, s32 *, 0xC) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0xC);
    M2C_FIELD(&D_800A63F0, s32 *, 0x10) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0x10);
    M2C_FIELD(&D_800A63F0, s32 *, 0x14) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0x14);
    M2C_FIELD(&D_800A63F0, s32 *, 0x18) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0x18);
    M2C_FIELD(&D_800A63F0, s32 *, 0x1C) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0x1C);
    D_800A6400 = 0;
    D_800A63F8 = 0;
    M2C_FIELD(&D_800A63F0, s32 *, 0) = 0;
    M2C_FIELD(&D_800A6558, s32 *, 0) = (s32) M2C_FIELD(&D_800A63F0, s32 *, 0);
    M2C_FIELD(&D_800A6558, s32 *, 4) = (s32) M2C_FIELD(&D_800A63F0, s32 *, 4);
    M2C_FIELD(&D_800A6558, s32 *, 8) = (s32) M2C_FIELD(&D_800A63F0, s32 *, 8);
    M2C_FIELD(&D_800A6558, s32 *, 0xC) = (s32) M2C_FIELD(&D_800A63F0, s32 *, 0xC);
    M2C_FIELD(&D_800A6558, s32 *, 0x10) = (s32) M2C_FIELD(&D_800A63F0, s32 *, 0x10);
    M2C_FIELD(&D_800A6558, s32 *, 0x14) = (s32) M2C_FIELD(&D_800A63F0, s32 *, 0x14);
    M2C_FIELD(&D_800A6558, s32 *, 0x18) = (s32) M2C_FIELD(&D_800A63F0, s32 *, 0x18);
    M2C_FIELD(&D_800A6558, s32 *, 0x1C) = (s32) M2C_FIELD(&D_800A63F0, s32 *, 0x1C);
    D_800A4F3C = 0;
    D_800A4F3E = 0;
    D_800A4F40 = 0;
    D_800A4F42 = 0;
    D_800A5E52 = 0;
    D_800A5E50 = 0;
    D_800AE822 = 0;
    D_800AE7F8 = ((s32) (D_800AE61C << 0xE) / (s32) D_800AE618) / 3;
    D_800AE820 = 0;
    D_80078817 = 2;
    D_80078827 = 2;
    D_800AE824 = (s16) D_800AE618;
    D_800AE826 = (s16) D_800AE61C;
    D_80078813 = 3;
    D_80078823 = 3;
    D_800C7C70 = 1;
}
