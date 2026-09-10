/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016DA7C,8016DB34).
 * Offset 0x45924 at overlay base 80128158. SHA256(span)=d0ef17f1eb876539951d712663084001e3b683f3e41ee8927d1fbf0cf1899f6d.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80181620->D_80181EA8; D_8018162C->D_80181EB4.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void *func_801465C0();
void func_80146C3C();
void func_8001CC3C();
void func_80128EA8();
extern s32 D_80181EA8;
extern s32 D_80181EB4;
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
    func_8001CC3C(in, &D_80181EA8, 0x250, 0x100);
    in->u27 = 0x90;
    in->u18 = 0x3000;
    in->u1A = 0x4000;
    in->u4 |= 0x50000000;
    func_80128EA8(in, (u8 *)p + 0x24, &D_80181EB4);
    p->u10 = 0;
    p->u14 = 0xFFF40000;
    p->u2++;
}
