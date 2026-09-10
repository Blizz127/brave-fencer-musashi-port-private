/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016BADC,8016BBA4).
 * Offset 0x43984 at overlay base 80128158. SHA256(span)=3a86038bb6e4406a8b2f8d10fbb8e944481f2d9a83cd16877033e862bba3140b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016badc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80146A6C(s32, s32, s32, s16, s32, s32, s32);     /* static */

void func_8016BADC(s32 arg0, s16 arg1, s32 arg2) {
    func_80146A6C(0x22, arg0, 0, arg1, 0, 0, arg2);
    func_80146A6C(0x22, arg0, 0, arg1, 0, 1, arg2);
    func_80146A6C(0x22, arg0, 0, arg1, 0, 2, arg2);
    func_80146A6C(0x24, arg0, 0, arg1, 0, 0, 0);
}
