/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015CA28,8015CB94).
 * Offset 0x348D0 at overlay base 80128158. SHA256(span)=33e8e3bb9499edfb6d08ccd5ce48b82e3a9e4daf335469909c727ea7e19df3a7.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_801809C0->D_80181248; D_80180A1C->D_801812A4.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
void func_80149FB0();
s32 func_80161B18();
s32 func_80161B84();
s32 func_801496D4();
void func_80149704();
s32 func_801487F4();
s32 func_801488A8();
s32 func_80148AAC();
void func_80147AD4();
void func_801473EC();
s32 func_8014D738();
void func_80146DB8();
void func_80146E90();
void func_80146C98();
void func_80147078();
void func_80159B70();
void func_80161240();
extern s32 D_80181248;
typedef struct {
    u16 idx;
    u8 pad2[0x16E]; s32 u170;
} T;
void func_8015CA28(T *p) {
    func_80149FB0(p);
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
    if (func_80148AAC(p) & 0xFF) {
        func_80147AD4(p, 0, 0, 0);
        func_801473EC(p);
    }
    if (func_8014D738(p)) {
        func_80146DB8(p, &D_80181248);
        func_80146E90(p, 0x14);
        func_80146C98(p, 2);
    }
    if (p->u170 == 0) {
        D_801812A4[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        func_80161240(p);
    }
}
