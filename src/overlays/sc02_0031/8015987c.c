/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015987C,801598BC).
 * Offset 0x31724 at overlay base 80128158. SHA256(span)=e28af0229af976e392a4a98a748f8294ad837062104ce20728783ba632e2f8d8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015987c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_800167B8();
typedef struct { u8 pad[0x15]; u8 unk15; } T;
s32 func_8015987C(T *p) {
    func_800167B8(4);
    p->unk15++;
    return 0;
}
