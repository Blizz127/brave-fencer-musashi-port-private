/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157808,80157880).
 * Offset 0x2F6B0 at overlay base 80128158. SHA256(span)=9fdd4eaad4109af6caf70898ca33e5302e4061e218b10169d9f9ceeddab4d98c.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_8018068C->D_80180F14; D_80184280->D_801A45A8.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80180F14[];
extern s32 D_801A45A8;
void func_801599A4();
void func_80159B3C();
void func_80157808(u16 *p) {
    D_80180F14[p[1]]();
    if (--D_801A45A8 == -1) {
        func_801599A4(p);
        func_80159B3C(p);
    }
}
