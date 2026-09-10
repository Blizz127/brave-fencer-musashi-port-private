/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015294C,80152A08).
 * Offset 0x2A7F4 at overlay base 80128158. SHA256(span)=a1c0d781839a1ca159a332084e01e9781e9b5b2a0a29abd96d95def22f9ae515.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015294c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80149020();
void func_801470B4();
void func_801470AC();
void func_80147A84();
void func_801473EC();
void func_80148038();
void func_80147460();
void func_801472C8();
void func_8015369C();
void func_80146CA0();
extern u16 D_800B99DA;
typedef struct { u8 pad[0xDE]; u8 uDE; } T;
void func_8015294C(T *p) {
    func_80149020(p);
    if (D_800B99DA & 1) {
        func_801470B4(p);
    } else {
        func_801470AC(p);
    }
    func_80147A84(p);
    func_801473EC(p);
    func_80148038(p, 0x18000);
    func_80147460(p);
    if (p->uDE-- == 0) {
        p->uDE = 0x10;
        func_801472C8(p);
        func_801470B4(p);
        func_8015369C(p);
        func_80146CA0(p);
    }
}
