/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E344,8015E40C).
 * Offset 0x361EC at overlay base 80128158. SHA256(span)=62c02df64be6907e3600983f2fea8724be5bc735abd93e89893062506c0eb67c.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A1C here is D_801812A4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
void func_8015E40C();
s32 func_80161B18();
s32 func_80161B84();
s32 func_80161208();
void func_8015E5B0();
void func_80147078();
void func_80159BE4();
typedef struct {
    u16 idx;
    u8 pad2[0xB6]; u16 b8;
    u8 padBA[0x17A]; s32 u234;
} T;
void func_8015E344(T *p) {
    func_8015E40C(p);
    if (func_80161B18(p)) {
        return;
    }
    if (func_80161B84(p)) {
        return;
    }
    if (func_80161208(p)) {
        return;
    }
    if (p->b8 & 0x4000) {
        func_8015E5B0(p);
        p->u234 = 1;
    }
    if (p->b8 & 0x8000) {
        D_801812A4[p->idx](p);
        func_80147078(p, 0);
        func_80159BE4(p);
    }
}
