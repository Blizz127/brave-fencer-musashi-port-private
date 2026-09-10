/* SC02.CD FILE_031 / ov_SC02_031 retail span [80158FA4,80159070).
 * Offset 0x30E4C at overlay base 80128158. SHA256(span)=df2fb864c655406f0ce63e751bd634ba155ac5a13c15575a9756e8516b8d89c6.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80184298->D_801A45C0.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
s32 func_80148800();
s32 func_801399F0();
void func_80139914();
s32 func_80159464();
void func_801594E8();
void func_80146C98();
void *func_8013767C();
void func_80146CA0();
extern s32 D_801A45C0;
extern s32 D_80110C3C;
typedef struct Inner { u8 pad[0x12]; u16 u12; } Inner;
typedef struct {
    u8 pad[0x20]; Inner *inner;
    u8 pad24[0x174]; void *u198;
} T;
void func_80158FA4(T *p) {
    s16 v;
    Inner *in = p->inner;
    in->u12 = (in->u12 + 0x16) & 0xFFF;
    if (func_80148800(p) & 0xF0) {
        D_801A45C0 = 1;
    }
    if (func_801399F0(p->u198) == 0) {
        return;
    }
    func_80139914(p->u198);
    p->u198 = 0;
    v = func_80159464(p);
    if (v) {
        func_801594E8(p, v);
        func_80146C98(p, 0xC);
    } else {
        p->u198 = func_8013767C(&D_80110C3C);
        func_80146CA0(p);
    }
}
