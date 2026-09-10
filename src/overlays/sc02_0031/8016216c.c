/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016216C,801621CC).
 * Offset 0x3A014 at overlay base 80128158. SHA256(span)=9a3b9e16e3ca5903d7434657841cae9cf3bb26f74bba9c7ef5a045413a48a20c.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_801842A0->D_801A45C8.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_800291C8();
void func_80016714();
extern void *D_801A45C8[3];
void func_8016216C(void) {
    s32 i;
    func_800291C8(8, 0);
    for (i = 0; i < 3; i++) {
        func_80016714(D_801A45C8[i], 0x38);
    }
}
