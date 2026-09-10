/* SC02 resident retail span [8015C944,8015CA28). Offset 0x347EC at base 80128158.
 * SHA256(span)=696661613d7ffc6f3f97ce0486b5d47b3da13cc86ee9d99ad254e5089e5efe7b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018730C[];
void func_80149FB0();
void func_80147AD4();
void func_801473EC();
void func_8014D738();
void func_80147078();
void func_80159B70();
s32 func_80161240();
s32 func_80146E98();
void func_80146CA0();
void func_80161C24();
typedef struct {
    u16 idx;
    u8 pad2[0xB6]; u16 b8;
    u8 padBA[0xB4]; u16 u16E;
    s32 u170;
} T;
void func_8015C944(T *p) {
    func_80149FB0(p);
    func_80147AD4(p, 0, 0, 0);
    func_801473EC(p);
    func_8014D738(p);
    if (p->u170 == 0) {
        D_8018730C[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else if (func_80161240(p) == 0) {
        if (func_80146E98(p)) {
            func_80146CA0(p);
        }
        if (p->b8 & 0x2000) {
            func_80161C24(p, p->u16E);
        }
    }
}
