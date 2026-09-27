/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012C098,8012C0EC).
 * Offset 0x3F40 at overlay base 80128158. SHA256(span)=f8b94a35af12890c5ea40a13c0703df6eb50d8a7353d73d4a72f5216055bfab2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012c098.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8012C218();
typedef struct Q { u8 pad[0xA]; u16 uA; } Q;
typedef struct {
    u8 pad[0x68]; Q *u68;
    u8 pad6C[6]; s16 u72;
} T;
void func_8012C098(T *p) {
    Q *q = p->u68;
    if (q && (p->u72 & 0x8000)) {
        q->uA &= 0x7FFF;
    }
    func_8012C218(p);
}
