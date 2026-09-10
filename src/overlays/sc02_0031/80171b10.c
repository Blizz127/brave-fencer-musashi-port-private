/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171B10,80171B44).
 * Offset 0x499B8 at overlay base 80128158. SHA256(span)=e4d26743d419195514953e78ab75fc0fa297cbc087eb5403dec76e41d8d1a3c3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171b10.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8014C568();
typedef struct Inner { u8 pad[0x12]; s16 unk12; } Inner;
typedef struct { u8 pad[0x20]; Inner *inner; } T;
void func_80171B10(T *p) {
    p->inner->unk12 = func_8014C568(p);
}
