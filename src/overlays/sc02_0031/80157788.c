/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157788,801577C8).
 * Offset 0x2F630 at overlay base 80128158. SHA256(span)=432e46cdddc6a8303e1904514c0e270858d7d80271051de55569649c02581881.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80184280->D_801A45A8.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_801A45A8;
void func_80147078();
void func_801578C0();
void func_80157788(void *p) {
    D_801A45A8 = 300;
    func_80147078(p, 7);
    func_801578C0(p);
}
