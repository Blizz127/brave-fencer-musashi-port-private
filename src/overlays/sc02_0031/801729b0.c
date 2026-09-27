/* SC02.CD FILE_031 / ov_SC02_031 retail span [801729B0,801729F0).
 * Offset 0x4A858 at overlay base 80128158. SHA256(span)=3ea927f670724ee1f9fdb066c66010412e5fd5db51d1028f62d6a51f1b27bfad.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801729b0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s16 D_80126B34;
extern s16 D_80126B30;
extern s16 D_80126B32;
void func_801729F0();
void func_80174684();
void func_801729B0(s32 a0) {
    D_80126B34 = a0;
    D_80126B30 = 0;
    D_80126B32 = 0;
    func_80174684(func_801729F0);
}
