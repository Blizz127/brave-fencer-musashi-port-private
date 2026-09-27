/* SC02 resident retail span [8015934C,801593E4). Offset 0x311F4 at base 80128158.
 * SHA256(span)=9db52a0554f130279a850021237dcde33366d8daada8961814b701adb1a6fd15.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80184288->D_801B6440; D_80184290->D_801B6448.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80145BF8();
void func_80146CA0();
extern s32 D_801B6440;
extern s32 D_801B6448;
extern u8 D_800AE6BD;
typedef struct Inner { u8 pad[0x12]; u16 u12; } Inner;
typedef struct { u8 pad[0x20]; Inner *inner; } T;
void func_8015934C(T *p) {
    Inner *in;
    if (D_801B6440 == 4) {
        D_801B6440 = 5;
    }
    if (D_801B6448) {
        func_80145BF8();
        func_80146CA0(p);
        D_800AE6BD = D_800AE6BD + 1;
    }
    in = p->inner;
    in->u12 = (in->u12 + 0x16) & 0xFFF;
}
