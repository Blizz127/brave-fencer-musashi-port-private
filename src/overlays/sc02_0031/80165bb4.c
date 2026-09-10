/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165BB4,80165BFC).
 * Offset 0x3DA5C at overlay base 80128158. SHA256(span)=adce9d6224331115ad430db669409aeacef09947482248013d460f4739389783.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165bb4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80154150();
void func_80154A74();
typedef struct {
    u8 pad_0[407];
    u8 idx;
} T;
void func_80165BB4(T *p) {
    func_80154150(p, 34);
    func_80154A74(p, 26);
    p->idx += 1;
}
