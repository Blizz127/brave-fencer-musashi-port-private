/* SC02 resident retail span [8015E344,8015E40C). Offset 0x361EC at base 80128158.
 * SHA256(span)=1de25e8669329f97cc4e94b10b57906458f1716b9338f714434bc42cbaf58e67.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018730C[];
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
        D_8018730C[p->idx](p);
        func_80147078(p, 0);
        func_80159BE4(p);
    }
}
