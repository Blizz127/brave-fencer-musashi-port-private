/* SC02.CD FILE_031 / ov_SC02_031 retail span [80162760,801627C0).
 * Offset 0x3A608 at overlay base 80128158. SHA256(span)=d810473a58e91a63977cd5bad1dee0458ad5ae76e3eeb70a0b95f13fa0ab4e84.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_801842F8->D_801A4620.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_800291C8();
void func_80016714();
extern void *D_801A4620[3];
void func_80162760(void) {
    s32 i;
    func_800291C8(0x12, 0);
    for (i = 0; i < 3; i++) {
        func_80016714(D_801A4620[i], 0x38);
    }
}
