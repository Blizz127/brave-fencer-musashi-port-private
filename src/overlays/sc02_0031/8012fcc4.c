/* SC02 resident retail span [8012FCC4,8012FDA8). Offset 0x7B6C at base 80128158.
 * SHA256(span)=bce7adfee381af77492c6c6d2c5719721ec4d7d5c1333b331b7e12eb21ae277f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E708->D_80184FF8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80131E00();
void func_80131B14();
s32 func_80131A34();
void func_8012B14C();
void func_80131CA8();
extern s32 D_80184FF8;
typedef struct {
    u8 pad[0x1C]; s32 u1C;
    u8 pad20[0x56]; s16 u76;
    u8 pad78[0x20]; s16 u98;
    u8 pad9A[0x1A]; s32 uB4;
    u8 padB8[9]; u8 uC1, uC2;
    u8 padC3; s32 uC4;
} T;
void func_8012FCC4(T *p) {
    p->uC1 = 8;
    if (p->uC4 & 2) {
        p->uC1 = 1;
        func_80131CA8(p, 3);
        return;
    }
    if (p->uC4 & 1) {
        func_80131E00(p, 1);
        return;
    }
    if ((p->uB4 & 0x100) == 0) {
        func_80131CA8(p, 0x1C);
        return;
    }
    func_80131B14(p);
    if (p->u76 <= 0) {
        func_80131E00(p, 0xC);
        return;
    }
    if (func_80131A34(p, 4)) {
        p->uC2 = 0;
    } else {
        p->u98 = 0;
        p->uC2 = 1;
    }
    func_8012B14C(p, &D_80184FF8);
    p->u1C = 0;
    func_80131CA8(p, 0x1C);
}
