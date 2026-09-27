/* SC02.CD FILE_031 / ov_SC02_031 retail span [801723C4,80172414).
 * Offset 0x4A26C at overlay base 80128158. SHA256(span)=6cbd881d1707994f579f71a8129198d583f1395f208327b75df6911b3ed7cd84.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801723c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801599A4();
void func_80147078();
void func_8014A1B0();
typedef struct { u8 pad[0x178]; s32 f178; } T;
void func_801723C4(T *p, s32 a1) {
    func_801599A4(p);
    func_80147078(p, 0xD);
    p->f178 = a1;
    func_8014A1B0(p, a1);
}
