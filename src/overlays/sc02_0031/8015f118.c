/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F118,8015F260).
 * Offset 0x36FC0 at overlay base 80128158. SHA256(span)=6edc1fd07569ee994ee89c85f9de0cdf106b32ebf203a07a500a586b6c2096c3.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A1C here is D_801812A4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
void func_80147078();
void func_80159B70();
void func_8014AB5C();
void func_801466F0();
void func_80019064();
void func_80147324();
s32 func_80161208();
void func_80155FF8();
extern s32 D_80062BE8;
typedef struct {
    u16 idx;
    u8 pad2[0x42]; s32 flags;
    u8 pad48[0x70]; u16 b8;
    u8 padBA[0xF0]; u8 u1AA;
} T;
void func_8015F118(T *p) {
    p->flags |= 2;
    if (p->b8 == 0x8000) {
        D_801812A4[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
        return;
    }
    if (p->b8 & 0x4000) {
        func_8014AB5C(0x19);
        func_8014AB5C(0x1D);
        func_801466F0(0x19, p, 0, 0, 0, 0, 0, 1);
        func_801466F0(0x19, p, 0, 0, 0, 1, 0, 1);
        func_801466F0(0x1D, p, 0, 0, 0, 0, 0, 1);
        func_80019064(&D_80062BE8);
        func_80147324(0x9DA);
    }
    if (func_80161208(p) == 0) {
        func_80155FF8(p, p->u1AA);
    }
}
