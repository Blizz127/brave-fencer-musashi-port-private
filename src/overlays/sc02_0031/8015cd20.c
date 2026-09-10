/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015CD20,8015CF24).
 * Offset 0x34BC8 at overlay base 80128158. SHA256(span)=398da0737cee3316abeaa039a56bba0642f7c62b555e67827e41ee81c14f9898.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_801809D0->D_80181258; D_80180A1C->D_801812A4; D_80180BC0->D_80181448; D_80180BD0->D_80181458.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
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
extern s32 D_80181258;
extern s32 D_80181448;
extern s32 D_80181458;
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
        D_801812A4[p->idx](p);
        p->u1BC = 0xA;
        func_80149724(p);
        if (func_80148AFC(p) & 0xFF) {
            func_80146DB8(p, &D_80181258);
        } else {
            func_80146D90(p);
        }
        return;
    }
    if (p->u234 == 0) {
        if (func_80148980(p)) {
            func_80146DB8(p, &D_80181448);
            func_80147A84(p);
            func_801473EC(p);
            func_80154150(p, 0x15);
            in = p->inner;
            in->u12 = (in->u12 - 0xAA) & 0xFFF;
        } else {
            if (func_8014891C(p)) {
                func_80146DB8(p, &D_80181458);
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
        D_801812A4[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        func_801725E0(p);
    }
}
