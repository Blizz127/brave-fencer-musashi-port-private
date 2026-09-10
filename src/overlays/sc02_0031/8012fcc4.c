/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012FCC4,8012FDA8).
 * Offset 0x7B6C at overlay base 80128158. SHA256(span)=533badf469ab7e113edfc71cc87bb2bd235f1c026ae4c5038d95b82518cf6f19.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_8017E708 here is D_8017EF90 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80131E00();
void func_80131B14();
s32 func_80131A34();
void func_8012B14C();
void func_80131CA8();
extern s32 D_8017EF90;
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
    func_8012B14C(p, &D_8017EF90);
    p->u1C = 0;
    func_80131CA8(p, 0x1C);
}
