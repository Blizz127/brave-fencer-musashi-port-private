/* SC02.CD FILE_031 / ov_SC02_031 retail span [801634D8,80163534).
 * Offset 0x3B380 at overlay base 80128158. SHA256(span)=ff19d27f89746b25447bad6a1574b566fd875684d6cebaf1199f6eb220f92d1c.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_8018393C->D_801A3E54.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 b[8]; } S;
extern S D_801A3E54;
void func_80163534();
void func_801634D8(s32 a0, s32 a1, s32 a2, s32 a3, u16 a4) {
    S tmp;
    tmp = D_801A3E54;
    func_80163534(a0, a1 & 0xFFFF, a2 & 0xFFFF, a3, a4, &tmp);
}
