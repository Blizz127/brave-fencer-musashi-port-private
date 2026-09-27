/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172ACC,80172B0C).
 * Offset 0x4A974 at overlay base 80128158. SHA256(span)=0159aeb4f8c6aa2100a50f0b20b158e388364ccd5065e63d9b93b985aea77987.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172acc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80171A1C();
void func_80174650();
typedef struct Inner { u8 pad[0x12]; u16 unk12; } Inner;
typedef struct {
    u8 pad[0x20];
    Inner *inner;
    u8 pad24[0x132-0x24];
    u16 f132;
    u8 pad134[2];
    s16 f136;
} T;
void func_80172ACC(T *p) {
    p->f136 = 0;
    p->inner->unk12 = p->f132;
    func_80171A1C(p);
    func_80174650(p);
}
