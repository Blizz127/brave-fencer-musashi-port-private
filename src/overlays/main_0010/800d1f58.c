/* MAIN10 resident retail span [800D1F58,800D1F90), offset 0x23160 at base 800AEDF8.
 * Donor: Druthulu resident_jr_800D128C func_800D1F58, cleaned to house style. */
#include "psx_types.h"

extern u16 D_80078EB4;
extern u16 D_80078EB8;
extern s32 D_80078E8C;
extern s32 D_8011DB14;
extern s32 D_8011DB1C;
extern s32 D_80128150;

void func_800D1F58(void) {
    D_8011DB14 = D_80078EB4;
    D_8011DB1C = D_80078EB8;
    D_80128150 = D_80078E8C;
}
