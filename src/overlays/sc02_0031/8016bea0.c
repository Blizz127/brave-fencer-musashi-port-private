/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016BEA0,8016BF34).
 * Offset 0x43D48 at overlay base 80128158. SHA256(span)=d2ff049f095aa942e17d5dc33191276558ba3ed9103b709ff8c41be0e00e6b90.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_801847F4->D_801A4B1C; D_801847F8->D_801A4B20.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_8016BF50();
void func_8016BFA8();
void func_80146C3C();
extern s32 D_801A4B1C;
extern s32 D_801A4B20;
typedef struct Inner { u8 pad[0x12]; u16 ang; u8 pad14[6]; s16 u1A; } Inner;
typedef struct { u8 pad[0x10]; s16 u10; u8 pad12[0xE]; Inner *inner; } T;
void func_8016BEA0(T *p) {
    Inner *in = p->inner;
    func_8016BF50(p);
    p->u10 -= 0x18;
    in->u1A += p->u10;
    in->ang = (in->ang + 0x22) & 0xFFF;
    func_8016BFA8(p, &D_801A4B1C, &D_801A4B20, (u8 *)in + 0x18);
    if (in->u1A < 0) {
        func_80146C3C(p);
    }
}
