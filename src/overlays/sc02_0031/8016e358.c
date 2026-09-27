/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E358,8016E3CC).
 * Offset 0x46200 at overlay base 80128158. SHA256(span)=45a91c3fda19b7f557c3a1de639091b7e89932e9248537d2cf6b84f78efb114d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e358.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_800D22E4();
void func_8016E460();
void func_80146C3C();
typedef struct {
    u8 pad[0x16]; s16 u16; u8 pad18[4]; s32 t;
    u8 pad20[0x10]; s32 u30;
} T;
void func_8016E358(T *p) {
    p->t--;
    if (p->t != 0) {
        func_800D22E4(p);
        p->u16 -= 3;
        p->u30 -= 0xE;
        func_8016E460(p, (u8 *)p + 0x38);
    } else {
        func_80146C3C(p);
    }
}
