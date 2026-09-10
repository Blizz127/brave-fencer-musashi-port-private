/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016B9F8,8016BA48).
 * Offset 0x438A0 at overlay base 80128158. SHA256(span)=f0eca3ab53cdb049cd59dacf292e2a7afd2ed7a784f8b78280bf830ed7003e35.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_801846B8->D_801A49E0.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_801A49E0;
s32 func_8012EFB8();
void func_80015954();
s32 func_8016B9F8(u8 *p) {
    s16 tmp[4];
    s32 v = func_8012EFB8(&D_801A49E0, tmp);
    func_80015954(tmp, p + 4);
    return (v & ~0x1000) != 0;
}
