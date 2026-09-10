/* SC02.CD FILE_031 / ov_SC02_031 retail span [80152E4C,80152EFC).
 * Offset 0x2ACF4 at overlay base 80128158. SHA256(span)=7a9d77ea877c81d13c007c724980b06707a8afe0a5087d382762dd85768b3e4a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80152e4c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80149020();
void func_80153B58();
void func_80147A84();
void func_801473EC();
void func_80148038();
void func_80147460();
void func_801472C8();
void func_801470B4();
void func_8015369C();
void func_80146CA0();
typedef struct { u8 pad[0xDE]; u8 uDE, uDF; } T;
void func_80152E4C(T *p) {
    func_80149020(p);
    func_80153B58(p);
    func_80147A84(p);
    func_801473EC(p);
    if (p->uDF == 0) {
        func_80148038(p, 0x18000);
    } else {
        p->uDF--;
    }
    func_80147460(p);
    if (p->uDE-- == 0) {
        p->uDE = 0x10;
        func_801472C8(p);
        func_801470B4(p);
        func_8015369C(p);
        func_80146CA0(p);
    }
}
