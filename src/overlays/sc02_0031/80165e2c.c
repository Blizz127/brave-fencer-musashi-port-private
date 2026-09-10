/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165E2C,80165E90).
 * Offset 0x3DCD4 at overlay base 80128158. SHA256(span)=99b8dcf8b401b11fa8c40dc93873a5a9fd422ea9f8f77cc4df4808fd40899378.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_8018394C->D_801A3E64.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_801A3E64;
void func_8001534C();
void func_800153CC();
void func_80165E2C(u16 *p) {
    func_8001534C(0, &D_801A3E64, 0x80, 0x80, 0, 0);
    func_800153CC(1, p[0], 0xA8, 0x80, 0x40, 0);
}
