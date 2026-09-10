/* SC02 resident retail span [8015FE70,8015FF20). Offset 0x37D18 at base 80128158.
 * SHA256(span)=31de3c0bffdc524665d8d7f2c8297a0d7bdf3741f987bbe662f920a0b4d2bee8.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018730C[];
void func_80147078();
void func_80159B70();
void func_80154A74();
void func_80161208();
typedef struct { u16 idx; u8 pad[0xB6]; u16 b8, ba; } T;
void func_8015FE70(T *p) {
    if ((p->b8 & 0x8000) && p->ba == 0) {
        D_8018730C[p->idx](p);
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
