/* SC02.CD FILE_031 / ov_SC02_031 retail span [801737B8,801737E8).
 * Offset 0x4B660 at overlay base 80128158. SHA256(span)=7f185115a94665c3ea95658fd2a087247a38547d1060c8414531b220fe138619.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801737b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s16 D_80126B30;
void func_801737E8();
void func_80174684();
void func_801737B8(s32 a0) {
    D_80126B30 = a0;
    func_80174684(func_801737E8);
}
