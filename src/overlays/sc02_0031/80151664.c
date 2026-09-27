/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151664,801516F0).
 * Offset 0x2950C at overlay base 80128158. SHA256(span)=a9ef468d8df37091cbe63d7920f6db95a6496bc75e3844e0e1e7b68b5c69de99.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151664.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80154A74();
void func_801553C0();
void func_801470AC();
void func_801472B4();
void func_801477E8();
void func_80153C18();
typedef struct Inner { u8 pad[0x10]; s16 unk10; } Inner;
typedef struct {
    u8 pad[0x20];
    Inner *inner;
    u8 pad24[0x18];
    u16 f3C, f3E, f40, f42;
    u8 pad44[0x1C];
    s16 f60, f62, f64;
    u8 pad66[0xDD-0x66];
    u8 fDD;
} T;
void func_80151664(T *p) {
    func_80154A74(p, 0x11);
    func_801553C0(p);
    func_801470AC(p);
    func_801472B4(p);
    p->f3E = 0;
    p->f40 = 0;
    p->f42 = 0;
    p->fDD = 0;
    p->f3C &= 0xFFFE;
    p->inner->unk10 = 0;
    p->f60 = 0x1000;
    p->f62 = 0x1000;
    p->f64 = 0x1000;
    func_801477E8(p, 0);
    func_80153C18(p);
}
