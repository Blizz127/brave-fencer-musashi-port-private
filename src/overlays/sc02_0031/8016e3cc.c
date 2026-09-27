/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E3CC,8016E460).
 * Offset 0x46274 at overlay base 80128158. SHA256(span)=e48e37da392849877ce26f1481e1241d7bd691908f8ad6201a0b0078be111c04.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e3cc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_800D20C0();
void func_800D23D0();
void func_80049A1C();
typedef struct Q {
    u8 pad[6]; u16 u6;
    u8 pad8[2]; u16 uA;
    u8 padC[2]; u16 uE;
} Q;
typedef struct {
    u8 pad[6]; u16 u6;
    u8 pad8[2]; u16 uA;
    u8 padC[2]; u16 uE;
    u8 pad10[0x24]; Q *u34;
} T;
void func_8016E3CC(T *p) {
    s16 a[4];
    s16 b[4];
    Q *q = p->u34;
    a[0] = q->u6;
    a[1] = q->uA - 0x28;
    a[2] = q->uE;
    func_800D20C0(a, b, 6);
    p->u6 = a[0];
    p->uA = a[1];
    p->uE = a[2];
    func_800D23D0(b);
    func_80049A1C(b, (u8 *)p + 0x38);
}
