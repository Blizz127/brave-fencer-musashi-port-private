/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016DBD8,8016DC20).
 * Offset 0x45A80 at overlay base 80128158. SHA256(span)=7e0d059d89ea7656a42f440afa268824db4857484cd4578caa738288e9a65a15.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016dbd8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80149374();
void func_800D1FC8();
typedef struct { s32 a, b, c, d; u8 pad[0x24]; void *p34; } T;
void func_8016DBD8(T *p) {
    p->b = 0;
    p->c = 0;
    p->d = 0;
    func_80149374(p->p34, &p->b);
    func_800D1FC8(p, 5);
}
