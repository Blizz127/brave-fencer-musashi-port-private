/* SC02.CD FILE_031 / ov_SC02_031 retail span [80163408,8016345C).
 * Offset 0x3B2B0 at overlay base 80128158. SHA256(span)=54b1ec340a2ca494d1b852b42f4f3e0d2d10450522ae65fd64b6274c6adb6259.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_8018393C->D_801A3E54.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 b[8]; } S;
extern S D_801A3E54;
void func_8016345C();
void func_80163408(s32 a0, s32 a1, s32 a2, s32 a3) {
    S tmp;
    tmp = D_801A3E54;
    func_8016345C(a0, a1 & 0xFFFF, a2, a3 & 0xFFFF, &tmp);
}
