/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E0D4,8015E150).
 * Offset 0x35F7C at overlay base 80128158. SHA256(span)=fb5e03317d60e5b953db44de9cfb468056674f0b9c2e00eed8877cdb174f9614.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e0d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8014C1A0();
void func_80015978();
s32 func_80029AAC();
void func_8014C4AC();
typedef struct Inner { u8 pad[0x12]; s16 u12; } Inner;
typedef struct {
    u8 pad[0x20]; Inner *inner;
    u8 pad24[0x154]; void *u178;
} T;
void func_8015E0D4(T *p) {
    s16 tmp[4];
    void *q = p->u178;
    s32 v;
    if (q == 0) {
        return;
    }
    func_8014C1A0(p, q);
    func_80015978((u8 *)q + 4, tmp);
    tmp[3] = 0;
    v = func_80029AAC();
    func_8014C4AC(q, 0x11, v, tmp, p->inner->u12);
    p->u178 = 0;
}
