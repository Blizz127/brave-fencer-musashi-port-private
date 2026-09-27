/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155B20,80155B9C).
 * Offset 0x2D9C8 at overlay base 80128158. SHA256(span)=c12ace7c8f1a07bb8427bea40be1c92cbfd204227ce65428ccb2b3811775ae7d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155b20.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80161208();
void func_80146D80();
void func_801477E8();
void func_80154274();
void func_80146CA0();
extern s32 D_800D4DA8;
typedef struct { u8 pad[0x44]; s32 flags; u8 pad48[0x70]; u16 f; } T;
void func_80155B20(T *p) {
    p->flags |= 2;
    if (func_80161208(p) == 0 && p->f == 0x8000) {
        func_80146D80(p);
        func_801477E8(p, 0xFFF00000);
        func_80154274(p, &D_800D4DA8);
        func_80146CA0(p);
    }
}
