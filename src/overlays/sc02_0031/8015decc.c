/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DECC,8015DF34).
 * Offset 0x35D74 at overlay base 80128158. SHA256(span)=28c5c43f15d92f3507a1a38e5f97b2585819ebb0ef2231dc27f67f7727f5877c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015decc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80154150();
void func_80154A74();
void func_8015E018();
void func_80147300();
void func_801553A8();
void func_8014BD60();
void func_80146CA0();
typedef struct { u8 pad[0x234]; s32 f234; } T;
void func_8015DECC(T *p) {
    func_80154150(p, 0x1C);
    func_80154A74(p, 0x19);
    p->f234 = 0;
    func_8015E018(p);
    func_80147300(0x5F5);
    func_801553A8(p);
    func_8014BD60(p, 4);
    func_80146CA0(p);
}
