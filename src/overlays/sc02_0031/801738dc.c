/* SC02.CD FILE_031 / ov_SC02_031 retail span [801738DC,8017390C).
 * Offset 0x4B784 at overlay base 80128158. SHA256(span)=7e2abc7f997678584a790ff0c5ec15565f6beb044f586c045912ee8da9595491.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801738dc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s16 D_80126B30;
void func_8017390C();
void func_80174684();
void func_801738DC(s32 a0) {
    D_80126B30 = a0;
    func_80174684(func_8017390C);
}
