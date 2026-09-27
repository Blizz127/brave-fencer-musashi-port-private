/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013A448,8013A4C4).
 * Offset 0x122F0 at overlay base 80128158. SHA256(span)=5f74c7afe1c4d53d2f201683688ecd7cdbf9dffd4ebdcfef9540329741cd4b02.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013a448.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8013A530();
typedef struct Q { u8 pad[0x28]; u16 u28, u2A; } Q;
typedef struct {
    u16 u0, u2;
    Q *q;
} T;
void func_8013A448(T *p) {
    Q *q = p->q;
    if (p->u2 == 0) {
        q->u2A = 0x400;
        q->u28 = 0x400;
        p->u2++;
    } else {
        q->u28 += 0x200;
        q->u2A += 0x200;
        if ((s16)q->u28 == 0x1000) {
            p->u0 = 2;
            p->u2 = 0;
        }
    }
    func_8013A530(p);
}
