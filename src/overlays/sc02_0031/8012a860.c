/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A860,8012A8B0).
 * Offset 0x2708 at overlay base 80128158. SHA256(span)=aa4a600719ae5bd3be5e3d9afe136511224b3974135ca3f3e8d4a5753de3e7cd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a860.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8012ACE0();
void func_8012AAAC();
typedef struct {
    u8 pad[0x72]; u16 f72;
    u8 pad74[0x1C]; s32 u90, u94;
    u8 pad98[2]; s16 u9a; s32 u9c;
} T;
void func_8012A860(T *p, s32 a1) {
    s32 v;
    p->u90 = a1;
    v = func_8012ACE0(p);
    p->u94 = v - 1;
    p->u9c = 0;
    p->u9a = 0;
    p->f72 |= 0x200;
    func_8012AAAC(p);
}
