/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165B6C,80165BB4).
 * Offset 0x3DA14 at overlay base 80128158. SHA256(span)=c3eb5257346c59a2deef2f226b32f27388ee70e6c1862279d8ed67f5a5eafcd8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165b6c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80161104();
void func_80165BB4();
typedef struct { u8 pad[0x197]; u8 unk197; } T;
void func_80165B6C(T *p) {
    if (func_80161104(p)) {
        func_80165BB4(p);
        p->unk197++;
    }
}
