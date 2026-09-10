/* SC02.CD FILE_031 / ov_SC02_031 retail span [801577C8,80157808).
 * Offset 0x2F670 at overlay base 80128158. SHA256(span)=95240c10acecb2448e1fff3f56317131db88a591b444af70f8d1fb48c7af0eb7.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80184280->D_801A45A8.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_801A45A8;
void func_80147078();
void func_80157808();
void func_801577C8(void *p) {
    D_801A45A8 = 300;
    func_80147078(p, 7);
    func_80157808(p);
}
