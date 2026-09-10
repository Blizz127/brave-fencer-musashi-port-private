/* SC02.CD FILE_031 / ov_SC02_031 retail span [801592CC,8015934C).
 * Offset 0x31174 at overlay base 80128158. SHA256(span)=3b68c56efdcac68b8393a4f46a5e1ac6639e043770a3e89a65933c264137f3d3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801592cc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_801399F0();
void func_80139914();
void *func_8013767C();
void func_80146C98();
extern s32 D_80110C3C;
typedef struct Inner { u8 pad[0x12]; u16 a; } Inner;
typedef struct { u8 pad[0x20]; Inner *inner; u8 pad24[0x174]; void *p198; } T;
void func_801592CC(T *p) {
    Inner *in = p->inner;
    in->a = (in->a + 0x16) & 0xFFF;
    if (func_801399F0(p->p198)) {
        func_80139914(p->p198);
        p->p198 = func_8013767C(&D_80110C3C);
        func_80146C98(p, 9);
    }
}
