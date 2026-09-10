/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012FDA8,8012FE70).
 * Offset 0x7C50 at overlay base 80128158. SHA256(span)=4616d1faacfc97d4726cd90b20428002bd355508f09a52a87f2a216b67aee5a6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012fda8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8012CBF4();
void func_80131E00();
void func_801319E0();
void func_80131C78();
void func_80131CA8();
typedef struct { u8 pad[0x1C]; s32 u1C; u8 pad20[0x94]; s32 uB4; } T;
void func_8012FDA8(T *p) {
    s32 v;
    u8 lo;
    if (p->uB4 & 0x100) {
        p->u1C = p->u1C + 1;
        if (p->u1C >= 0x15) {
            func_80131E00(p, 0xD);
            return;
        }
        v = func_8012CBF4(p);
        if (v & 0x2000) {
            lo = (u8)v;
            if (lo == 2) {
                func_80131E00(p, 0x12);
                return;
            }
            if (lo == 0x1A) {
                func_801319E0(p);
                return;
            }
            func_80131C78(p);
        }
    }
    func_80131CA8(p, 0x1D);
}
