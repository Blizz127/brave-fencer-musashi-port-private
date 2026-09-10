/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E6E4,8016E728).
 * Offset 0x4658C at overlay base 80128158. SHA256(span)=2c5846ee073578744a808840174955dcf1a9edcc6a1cc9e34940b2748f6bf39a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e6e4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8016E778();
typedef struct {
    u8 pad[2]; u16 u2;
    u8 pad4[0x18]; s32 u1C;
} T;
void func_8016E6E4(T *p) {
    p->u1C = p->u1C - 1;
    if (p->u1C == -1) {
        p->u2 = p->u2 + 1;
    }
    func_8016E778(p);
}
