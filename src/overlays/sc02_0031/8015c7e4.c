/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015C7E4,8015C944).
 * Offset 0x3468C at overlay base 80128158. SHA256(span)=a40eb76af87ee7c362e8c83e197500398dd2bf2455ab1a943130b3f012a5183f.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_801809C0->D_80181248; D_80180A1C->D_801812A4.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
s32 func_80161B18();
s32 func_80161B84();
s32 func_801496D4();
void func_80149704();
s32 func_801487F4();
s32 func_801488A8();
void func_80147078();
void func_80159B70();
s32 func_80161240();
s32 func_80146E98();
void func_80148AAC();
void func_80146DB8();
void func_80146E90();
void func_80146CA0();
void func_80161C24();
void func_8014C010();
extern s32 D_80181248;
typedef struct {
    u16 idx;
    u8 pad2[0xB6]; u16 b8;
    u8 padBA[0xB4]; u16 u16E;
} T;
void func_8015C7E4(T *p) {
    if (func_80161B18(p)) {
        return;
    }
    if (func_80161B84(p)) {
        return;
    }
    if (func_801496D4(p)) {
        D_801812A4[p->idx](p);
        func_80149704(p);
        return;
    }
    if ((func_801487F4(p) & 0x80) == 0 && func_801488A8(p) == 0) {
        D_801812A4[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
        return;
    }
    if (func_80161240(p)) {
        return;
    }
    if (func_80146E98(p)) {
        func_80148AAC(p);
        func_80146DB8(p, &D_80181248);
        func_80146E90(p, 0x14);
        func_80146CA0(p);
    }
    if (p->b8 & 0x2000) {
        func_80161C24(p, p->u16E);
        func_8014C010(p, 2);
    }
}
