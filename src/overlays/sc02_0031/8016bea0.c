/* SC02 resident retail span [8016BEA0,8016BF34). Offset 0x43D48 at base 80128158.
 * SHA256(span)=198ac5e730eb3dc1c6220b6277c01195a2bf5672d6bfa3129276fa7b8fae0776.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801847F4->D_801B69AC; D_801847F8->D_801B69B0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_8016BF50();
void func_8016BFA8();
void func_80146C3C();
extern s32 D_801B69AC;
extern s32 D_801B69B0;
typedef struct Inner { u8 pad[0x12]; u16 ang; u8 pad14[6]; s16 u1A; } Inner;
typedef struct { u8 pad[0x10]; s16 u10; u8 pad12[0xE]; Inner *inner; } T;
void func_8016BEA0(T *p) {
    Inner *in = p->inner;
    func_8016BF50(p);
    p->u10 -= 0x18;
    in->u1A += p->u10;
    in->ang = (in->ang + 0x22) & 0xFFF;
    func_8016BFA8(p, &D_801B69AC, &D_801B69B0, (u8 *)in + 0x18);
    if (in->u1A < 0) {
        func_80146C3C(p);
    }
}
