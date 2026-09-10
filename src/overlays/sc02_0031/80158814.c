/* SC02.CD FILE_031 / ov_SC02_031 retail span [80158814,80158880).
 * Offset 0x306BC at overlay base 80128158. SHA256(span)=a932372a3f7f7ef62fd8556a62286223d0b8355f57818ebf510e0601a3a0287e.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80184288->D_801A45B0; D_80184294->D_801A45BC; D_80184298->D_801A45C0.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_801A45B0;
extern s32 D_801A45BC;
extern s32 D_801A45C0;
void func_80147084();
void func_80147098();
void func_801470AC();
void func_80147078();
void func_80158880();
typedef struct { u8 pad[0xA8]; u8 fA8; } T;
void func_80158814(T *p) {
    D_801A45B0 = 0;
    D_801A45BC = 1;
    D_801A45C0 = 0;
    p->fA8 = 0;
    func_80147084(p);
    func_80147098(p);
    func_801470AC(p);
    func_80147078(p, 0x1A);
    func_80158880(p);
}
