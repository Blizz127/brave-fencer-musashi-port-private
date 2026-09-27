/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E688,8016E6E4).
 * Offset 0x46530 at overlay base 80128158. SHA256(span)=ef2ac4cdbfcd283e9d2bd04f579791cf5d1bfc476064a6447ff728cf8e2eac5d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e688.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8016E778();
typedef struct {
    u8 pad[2]; u16 u2;
    u8 pad4[0xC]; u16 u10, u12;
    u8 pad14[8]; s32 u1C;
} T;
void func_8016E688(T *p) {
    p->u10 = p->u10 + 0x200;
    p->u12 = p->u12 + p->u10;
    if ((s16)p->u12 >= 0x3000) {
        p->u1C = 4;
        p->u2 = p->u2 + 1;
    }
    func_8016E778(p);
}
