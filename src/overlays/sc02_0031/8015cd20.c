/* SC02 resident retail span [8015CD20,8015CF24). Offset 0x34BC8 at base 80128158.
 * SHA256(span)=9d27d56ee5198a1156a140ba6b945c53f758793787370915d17b103c246af654.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801809D0->D_801872C0; D_80180A1C->D_8018730C; D_80180BC0->D_801874B0; D_80180BD0->D_801874C0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018730C[];
void func_80149FB0();
s32 func_801496D4();
void func_80149724();
s32 func_80148AFC();
void func_80146DB8();
void func_80146D90();
s32 func_80148980();
void func_80147A84();
void func_801473EC();
void func_80154150();
s32 func_8014891C();
s32 func_801489E8();
s32 func_80148A48();
void func_8014FA04();
s32 func_8014E434();
void func_80147078();
void func_80159B70();
void func_801725E0();
extern s32 D_801872C0;
extern s32 D_801874B0;
extern s32 D_801874C0;
typedef struct Inner { u8 pad[0x12]; u16 u12; } Inner;
typedef struct {
    u16 idx;
    u8 pad2[0x1E]; Inner *inner;
    u8 pad24[0x94]; u16 b8;
    u8 padBA[0x102]; u8 u1BC;
    u8 pad1BD[0x77]; s32 u234;
} T;
void func_8015CD20(T *p) {
    Inner *in;
    func_80149FB0(p);
    if (func_801496D4(p)) {
        D_8018730C[p->idx](p);
        p->u1BC = 0xA;
        func_80149724(p);
        if (func_80148AFC(p) & 0xFF) {
            func_80146DB8(p, &D_801872C0);
        } else {
            func_80146D90(p);
        }
        return;
    }
    if (p->u234 == 0) {
        if (func_80148980(p)) {
            func_80146DB8(p, &D_801874B0);
            func_80147A84(p);
            func_801473EC(p);
            func_80154150(p, 0x15);
            in = p->inner;
            in->u12 = (in->u12 - 0xAA) & 0xFFF;
        } else {
            if (func_8014891C(p)) {
                func_80146DB8(p, &D_801874C0);
                func_80147A84(p);
                func_801473EC(p);
                func_80154150(p, 0x14);
                p->b8 = 1;
            }
            if (func_801489E8(p)) {
                in = p->inner;
                in->u12 = (in->u12 + 0x71) & 0xFFF;
            } else if (func_80148A48(p)) {
                in = p->inner;
                in->u12 = (in->u12 - 0x71) & 0xFFF;
            }
        }
    } else {
        p->u234--;
    }
    func_8014FA04(p);
    if (func_8014E434(p) == 0) {
        D_8018730C[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        func_801725E0(p);
    }
}
