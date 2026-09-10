/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015934C,801593E4).
 * Offset 0x311F4 at overlay base 80128158. SHA256(span)=df82ab9bbd378d05281092df4a017c936b0e3026d8620ce69a54781383cad6a6.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80184288->D_801A45B0; D_80184290->D_801A45B8.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80145BF8();
void func_80146CA0();
extern s32 D_801A45B0;
extern s32 D_801A45B8;
extern u8 D_800AE6BD;
typedef struct Inner { u8 pad[0x12]; u16 u12; } Inner;
typedef struct { u8 pad[0x20]; Inner *inner; } T;
void func_8015934C(T *p) {
    Inner *in;
    if (D_801A45B0 == 4) {
        D_801A45B0 = 5;
    }
    if (D_801A45B8) {
        func_80145BF8();
        func_80146CA0(p);
        D_800AE6BD = D_800AE6BD + 1;
    }
    in = p->inner;
    in->u12 = (in->u12 + 0x16) & 0xFFF;
}
