/* SC02 resident retail span [801602A4,8016032C). Offset 0x3814C at base 80128158.
 * SHA256(span)=44c53c47d1582fbff72e8af451df527080e0978caa504c68a42588139506f1db.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018730C[];
void func_80154A74();
void func_80147078();
void func_80159B70();
s32 func_80161208();
typedef struct { u16 idx; u8 pad[0xB6]; u16 b8; } T;
void func_801602A4(T *p) {
    if (p->b8 == 0x8000) {
        D_8018730C[p->idx](p);
        func_80154A74(p, 0x11);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        func_80161208(p);
    }
}
