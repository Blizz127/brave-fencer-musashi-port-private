/* SC02 resident retail span [8015DBD4,8015DC84). Offset 0x35A7C at base 80128158.
 * SHA256(span)=4b13e18ed06b8aeb807cad3a760fc22d65f98bbddfec9bd6ff1d8cf9c5ef6958.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018730C[];
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
        D_8018730C[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        if (p->u178) {
            func_8015DCB8(p);
        }
        func_80161208(p);
    }
}
