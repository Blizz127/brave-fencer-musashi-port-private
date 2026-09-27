/* SC02 resident retail span [80140F00,80141100). Offset 0x18DA8 at base 80128158.
 * SHA256(span)=33f32e7363865405f2c00a946bda10a7a4ae409f1357918b16cf6e22af753761.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017F324->D_80185C14; D_8017F344->D_80185C34; D_8017F348->D_80185C38; D_8017F34C->D_80185C3C; D_8017F350->D_80185C40; D_8017F354->D_80185C44.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_80029FD4();                                /* extern */
s32 func_80029FE4();                                /* extern */
s32 func_8002A26C();                                /* extern */
s32 func_8002A2B0();                                /* extern */
s32 func_8002A4B8();                                /* extern */
s32 func_8002A4FC();                                /* extern */
s32 func_8002A728();                                /* extern */
s32 func_8002A76C();                                /* extern */
s32 func_8002A998();                                /* extern */
s32 func_8002A9DC();                                /* extern */
s32 func_8002AAB4();                                /* extern */
void func_8005C540(s32, s32);                          /* extern */
s32 func_800D2CA8(s32, s32);                          /* extern */
void func_800D2D10(s32, s32, s32, s32);                    /* extern */
extern s32 D_80185C14;
extern s32 D_80185C34;
extern s32 D_80185C38;
extern s32 D_80185C3C;
extern s32 D_80185C40;
extern s32 D_80185C44;
extern s16 D_80115128;

void func_80140F00(void) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s0_6;

    if (D_80115128 == 0) {
        temp_s0 = D_80185C14;
        func_800D2D10(func_800D2CA8(func_80029FE4() + 1, 0x18), 2, temp_s0 + 4, 1);
        func_8005C540(temp_s0 + 0xA, func_8002AAB4());
        temp_s0_2 = D_80185C34;
        func_800D2D10(func_800D2CA8(func_8002A26C() + 1, 0x18), 2, temp_s0_2 + 0x12, 1);
        func_800D2D10(func_800D2CA8(func_8002A2B0(), 0x18), 2, temp_s0_2 + 0x22, -1);
        temp_s0_3 = D_80185C38;
        func_800D2D10(func_800D2CA8(func_8002A4B8() + 1, 0x18), 2, temp_s0_3 + 0x12, 1);
        func_800D2D10(func_800D2CA8(func_8002A4FC(), 0x18), 2, temp_s0_3 + 0x22, -1);
        temp_s0_4 = D_80185C3C;
        func_800D2D10(func_800D2CA8(func_8002A998() + 1, 0x18), 2, temp_s0_4 + 0x12, 1);
        func_800D2D10(func_800D2CA8(func_8002A9DC(), 0x18), 2, temp_s0_4 + 0x22, -1);
        temp_s0_5 = D_80185C40;
        func_800D2D10(func_800D2CA8(func_8002A728() + 1, 0x18), 2, temp_s0_5 + 0x12, 1);
        func_800D2D10(func_800D2CA8(func_8002A76C(), 0x18), 2, temp_s0_5 + 0x22, -1);
        temp_s0_6 = D_80185C44;
        func_800D2D10(func_800D2CA8(func_80029FD4(), 4), 7, temp_s0_6 + 0x18, -1);
    }
}

