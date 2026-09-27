/* SC02.CD FILE_031 / ov_SC02_031 retail span [801516F0,8015173C).
 * Offset 0x29598 at overlay base 80128158. SHA256(span)=b37632c15ecb3f83ad6b59b424d0131850f7c9834639d01e1928b6fbcd55cfa0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801516f0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8014C8F0();
void func_80147078();
void func_80151780();
typedef struct {
    u16 f0;
    s16 f2;
    u8 pad_4[218];
    u8 fDE;
} T;
void func_801516F0(T *p) {
    func_8014C8F0(p);
    p->fDE = (u8) p->f0;
    func_80147078(p, 25);
    p->f2 = 1;
    func_80151780(p);
}
