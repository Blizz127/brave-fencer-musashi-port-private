/* SC02.CD FILE_031 / ov_SC02_031 retail span [80138B88,80138BE0).
 * Offset 0x10A30 at overlay base 80128158. SHA256(span)=cf0c9a765e33c31b3a824ddfd3dfa974f7ae1b43603937d5b06679f31b19bb99.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80138b88.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct {
    u8 pad[4]; s16 u4;
    u8 pad6[2]; s32 u8;
    u8 padC[0xC]; u16 u18;
    u8 pad1A[0x26]; s16 *u40;
} T;
void func_80138B88(T *p) {
    if (p->u8 & 0x2000) {
        p->u4 = 0xD;
    } else {
        p->u4 = 0xC;
        p->u8 &= -0x1001;
        if (p->u40 != 0 && p->u18 != 0) {
            p->u40[0] = 3;
        }
    }
}
