/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DF34,8015DFE4).
 * Offset 0x35DDC at overlay base 80128158. SHA256(span)=25ac53cb79beaf2712a372c62badb451f6a6d75ce39b1841a5c90066a27a1630.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A1C here is D_801812A4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
void func_8015E0D4();
void func_80147078();
void func_80159B70();
void func_8015E018();
void func_80161208();
typedef struct {
    u16 idx;
    u8 pad2[0xB6]; u16 b8;
    u8 padBA[0xBE]; void *u178;
} T;
void func_8015DF34(T *p) {
    if (p->b8 & 0x4000) {
        func_8015E0D4(p);
    }
    if (p->b8 == 0x8000) {
        D_801812A4[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        if (p->u178) {
            func_8015E018(p);
        }
        func_80161208(p);
    }
}
