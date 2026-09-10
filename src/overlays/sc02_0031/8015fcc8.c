/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015FCC8,8015FD74).
 * Offset 0x37B70 at overlay base 80128158. SHA256(span)=661cc059d40643fe5969d0cfd4b412b45a221f1d6b6d6708385b0731dceca232.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A1C here is D_801812A4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
void func_8016007C();
void func_80147078();
void func_80159B70();
void func_8014BFF4();
void func_80146CA0();
extern s32 D_800AE6B0;
typedef struct {
    u16 idx;
    u8 pad2[0xBC]; u8 uBE, uBF;
    u8 padC0[0xC4]; s32 u184;
    u8 pad188[0xF]; u8 u197;
    u8 pad198[8]; u8 u1A0;
} T;
void func_8015FCC8(T *p) {
    if (D_800AE6B0 & 0x80FFFFFF) {
        func_8016007C();
        D_801812A4[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        p->u197 = 0;
        p->uBE = 0;
        p->uBF = 0;
        p->u1A0 = p->u184;
        func_8014BFF4(p, 1);
        func_80146CA0(p);
    }
}
