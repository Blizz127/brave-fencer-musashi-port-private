/* SC02.CD FILE_031 / ov_SC02_031 retail span [80168EC4,80168F40).
 * Offset 0x40D6C at overlay base 80128158. SHA256(span)=5f4e1dafe1416bcb284d024d95aadc7f5bed30fbb141949a7ebf27872a516184.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80168ec4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80168F40();
void func_800D22E4();
void func_80146C3C();
typedef struct {
    u8 pad[6]; s16 u6; u8 pad8[2]; s16 uA; u8 padC[2]; s16 uE;
    s16 u10; u8 pad12[2]; s16 u14; u8 pad16[2]; s16 u18;
    s32 u1c;
} T;
void func_80168EC4(T *p) {
    if (p->u1c < 5) {
        func_80168F40();
        p->u10 = p->u6;
        p->u14 = p->uA;
        p->u18 = p->uE;
        func_800D22E4(p);
        p->u1c++;
    } else {
        func_80146C3C(p);
    }
}
