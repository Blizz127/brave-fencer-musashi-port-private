/* SC02.CD FILE_031 / ov_SC02_031 retail span [801602A4,8016032C).
 * Offset 0x3814C at overlay base 80128158. SHA256(span)=038f93e6839b7993912fb03615799236151bb23678f73cb40bfbdba3d008b4c3.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A1C here is D_801812A4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
void func_80154A74();
void func_80147078();
void func_80159B70();
s32 func_80161208();
typedef struct { u16 idx; u8 pad[0xB6]; u16 b8; } T;
void func_801602A4(T *p) {
    if (p->b8 == 0x8000) {
        D_801812A4[p->idx](p);
        func_80154A74(p, 0x11);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        func_80161208(p);
    }
}
