/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015EEE0,8015EF9C).
 * Offset 0x36D88 at overlay base 80128158. SHA256(span)=b3c359a19a1c364e67034b5d28a1ba56bb964dc2c7b8b254d044fe87120d5dc7.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A1C here is D_801812A4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
void func_80148038();
void func_80147460();
void func_80147AD4();
void func_801473EC();
void func_80147078();
void func_80159B70();
s32 func_80161418();
void func_801725A4();
typedef struct { u16 idx; u8 pad[0xB6]; u16 b8; } T;
void func_8015EEE0(T *p) {
    func_80148038(p, 0x10000);
    func_80147460(p);
    func_80147AD4(p, 0, 0, 0x1000);
    func_801473EC(p);
    if (p->b8 & 0x8000) {
        D_801812A4[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else if (func_80161418(p) == 0) {
        func_801725A4(p);
    }
}
