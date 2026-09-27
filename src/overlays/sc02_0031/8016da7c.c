/* SC02 resident retail span [8016DA7C,8016DB34). Offset 0x45924 at base 80128158.
 * SHA256(span)=9814baa5840ac155d4aa972796eb1bdf66a9168120dbacbee4a161930b9903ed.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181620->D_80187F10; D_8018162C->D_80187F1C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void *func_801465C0();
void func_80146C3C();
void func_8001CC3C();
void func_80128EA8();
extern s32 D_80187F10;
extern s32 D_80187F1C;
typedef struct Inner {
    u8 pad[4]; s32 u4;
    u8 pad8[0x10]; s16 u18, u1A;
    u8 pad1C[0xB]; u8 u27;
} Inner;
typedef struct {
    u8 pad[2]; u16 u2;
    u8 pad4[0xC]; s32 u10, u14;
    u8 pad18[8]; Inner *inner;
} T;
void func_8016DA7C(T *p) {
    Inner *in = func_801465C0(p);
    if (in == 0) {
        func_80146C3C(p);
        return;
    }
    p->inner = in;
    func_8001CC3C(in, &D_80187F10, 0x250, 0x100);
    in->u27 = 0x90;
    in->u18 = 0x3000;
    in->u1A = 0x4000;
    in->u4 |= 0x50000000;
    func_80128EA8(in, (u8 *)p + 0x24, &D_80187F1C);
    p->u10 = 0;
    p->u14 = 0xFFF40000;
    p->u2++;
}
