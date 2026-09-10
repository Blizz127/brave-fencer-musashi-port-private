/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015FE70,8015FF20).
 * Offset 0x37D18 at overlay base 80128158. SHA256(span)=bd3f6409ec386056b4ea53f672205e265a314bbe779f15418b0aee0d44bd3a32.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A1C here is D_801812A4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
void func_80147078();
void func_80159B70();
void func_80154A74();
void func_80161208();
typedef struct { u16 idx; u8 pad[0xB6]; u16 b8, ba; } T;
void func_8015FE70(T *p) {
    if ((p->b8 & 0x8000) && p->ba == 0) {
        D_801812A4[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        if (p->b8 & 0x8000) {
            p->b8 = p->ba;
        }
        if (p->b8 & 0x4000) {
            func_80154A74(p, 0x11);
        }
        func_80161208(p);
    }
}
