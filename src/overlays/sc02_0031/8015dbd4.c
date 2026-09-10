/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DBD4,8015DC84).
 * Offset 0x35A7C at overlay base 80128158. SHA256(span)=d8184bb252bab731a2d81c8c7ff342a5a55d13a325d1ed2954eed69ec575424f.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A1C here is D_801812A4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
void func_8015DD74();
void func_80147078();
void func_80159B70();
void func_8015DCB8();
void func_80161208();
typedef struct {
    u16 idx;
    u8 pad2[0xB6]; u16 b8;
    u8 padBA[0xBE]; void *u178;
} T;
void func_8015DBD4(T *p) {
    if (p->b8 & 0x4000) {
        func_8015DD74(p);
    }
    if (p->b8 == 0x8000) {
        D_801812A4[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        if (p->u178) {
            func_8015DCB8(p);
        }
        func_80161208(p);
    }
}
