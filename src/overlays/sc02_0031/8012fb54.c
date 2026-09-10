/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012FB54,8012FC30).
 * Offset 0x79FC at overlay base 80128158. SHA256(span)=c781d8e87f9aa4bf40536cd7163f66de1d5263606aab58b86cfbe58619e90e68.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012fb54.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801319E0();
s16 *func_80143B6C();
void func_8002D4C8();
void func_80131CA8();
typedef struct {
    u8 pad[4]; s32 u4, u8, uC;
    s32 u10, u14, u18, u1C;
    u8 pad20[0x8C]; u16 uAC;
    u8 padAE[6]; s32 uB4;
} T;
typedef struct { u8 pad[0xA]; s16 uA; } R;
void func_8012FB54(T *p) {
    R *r;
    if (p->uB4 & 0x10000) {
        p->u4 += p->u10;
        p->u8 += p->u14;
        p->uC += p->u18;
        p->u1C--;
        if (p->u1C == 0) {
            func_801319E0(p);
        } else {
            r = func_80143B6C(p, 1);
            if (r) {
                r->uA += p->uAC;
            }
            if (p->u1C == 0x13) {
                func_8002D4C8(0x8F2, 0);
            }
        }
    }
    func_80131CA8(p, 0x36);
}
