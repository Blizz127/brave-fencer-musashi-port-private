/* SC02.CD FILE_031 / ov_SC02_031 retail span [80158038,801580B4).
 * Offset 0x2FEE0 at overlay base 80128158. SHA256(span)=29dd84508b05f98ec81bd4cc3890690f1c2ecc567d43f58dcb0ba22cc96d22eb.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801806A0 here is D_80180F28 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_800D51E0;
extern s32 D_80180F28;
void func_80154274();
void func_80154A74();
void func_80146DB8();
void func_80146994();
void func_80147324();
void func_80146CA0();
typedef struct {
    u8 pad[0x1AA];
    u8 f1AA;
    u8 pad1AB[0x234-0x1AB];
    s32 f234;
} T;
void func_80158038(T *p) {
    p->f1AA = 0xE;
    func_80154274(p, &D_800D51E0);
    func_80154A74(p, 0x15);
    func_80146DB8(p, &D_80180F28);
    p->f234 = 0;
    func_80146994(5, p, 0xC, 0);
    func_80147324(0x455);
    func_80146CA0(p);
}
