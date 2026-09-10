/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161124,80161208).
 * Offset 0x38FCC at overlay base 80128158. SHA256(span)=0be102edccd7b7b305631b7040885033ebd06158272576c8e6b249ff928d024c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161124.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801483E8();
void func_8014CBF8();
void func_801474EC();
void func_80154150();
void func_80154A74();
void func_80146E90();
s32 func_80149184();
void func_801553A8();
void func_801725A4();
s32 func_80161A60();
void func_80147324();
extern s16 D_801152A0;
typedef struct {
    u8 pad[0x24]; s32 u24;
    u8 pad28[4]; s32 u2C;
    u8 pad30[0x2C]; s32 u5C;
    u8 pad60[0x1E0]; s32 u240;
    u8 pad244[6]; s16 u24A;
} T;
void func_80161124(T *p) {
    p->u24A = 0;
    func_801483E8(p);
    func_8014CBF8(p);
    func_801474EC(p);
    if (p->u2C < -0xBA000) {
        p->u2C = -0xBA000;
    }
    if (p->u24 | p->u2C) {
        func_80154150(p, 0xF);
    } else {
        func_80154150(p, 0xD);
    }
    func_80154A74(p, 0x22);
    p->u5C = 0;
    p->u240 = 0;
    func_80146E90(p, 4);
    D_801152A0 = func_80149184(p);
    func_801553A8(p);
    func_801725A4(p);
    if (func_80161A60(p)) {
        func_80147324(0x8E1);
    }
}
