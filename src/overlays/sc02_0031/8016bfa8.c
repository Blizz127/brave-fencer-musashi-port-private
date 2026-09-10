/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016BFA8,8016BFD0).
 * Offset 0x43E50 at overlay base 80128158. SHA256(span)=fcbac97a8dd5ff834700a16227cab0e9cdaa3bf2fd30dd1c77bcf82f5e18a69b.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80184780->D_801A4AA8.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_8016BFD0();
extern s32 D_801A4AA8;
void func_8016BFA8(void *a0, void *a1, void *a2, void *a3) {
    func_8016BFD0(a0, a1, a2, a3, &D_801A4AA8);
}
