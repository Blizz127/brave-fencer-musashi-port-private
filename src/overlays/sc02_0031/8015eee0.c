/* SC02 resident retail span [8015EEE0,8015EF9C). Offset 0x36D88 at base 80128158.
 * SHA256(span)=7807603b4d405c6effde5955b892a1805098b36542d2bd5cffa60da6ffc7581e.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018730C[];
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
        D_8018730C[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else if (func_80161418(p) == 0) {
        func_801725A4(p);
    }
}
