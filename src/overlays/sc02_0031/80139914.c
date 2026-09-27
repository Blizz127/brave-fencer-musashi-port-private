/* SC02.CD FILE_031 / ov_SC02_031 retail span [80139914,80139954).
 * Offset 0x117BC at overlay base 80128158. SHA256(span)=5ccd35eb71ac29e394c26e5f97e6c5879adb3e1cb55b1d1a6ad668ad7894ad82.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80139914.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8013A8B0();
typedef struct {
    s32 u0;
    s16 u4;
    u8 pad6[0x12]; u16 u18;
    u8 pad1A[0x26]; void *u40;
} T;
void func_80139914(T *p) {
    p->u4 = 0;
    p->u0 = 0;
    if (p->u18 && p->u40) {
        func_8013A8B0(p->u40);
    }
}
