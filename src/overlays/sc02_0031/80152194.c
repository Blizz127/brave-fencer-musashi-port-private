/* SC02.CD FILE_031 / ov_SC02_031 retail span [80152194,8015220C).
 * Offset 0x2A03C at overlay base 80128158. SHA256(span)=5ebd73251eb556b0c5e9b9fd3f79378aaa96abe3a24402a17d50c1454369242d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80152194.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80149020();
void func_80147A84();
void func_801473EC();
void func_80148038();
void func_80147460();
void func_801470B4();
void func_8015369C();
void func_80146CA0();
typedef struct { u8 pad[0xDE]; u8 uDE; } T;
void func_80152194(T *p) {
    func_80149020(p);
    func_80147A84(p);
    func_801473EC(p);
    func_80148038(p, 0x4000);
    func_80147460(p);
    if (p->uDE-- == 0) {
        func_801470B4(p);
        func_8015369C(p);
        func_80146CA0(p);
    }
}
