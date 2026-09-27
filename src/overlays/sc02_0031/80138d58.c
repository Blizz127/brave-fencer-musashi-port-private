/* SC02.CD FILE_031 / ov_SC02_031 retail span [80138D58,80138DB8).
 * Offset 0x10C00 at overlay base 80128158. SHA256(span)=09d64d91677c81db247b35e832f825758869a2d960e438978e5e8bcc9c97c61c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80138d58.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8013A9F8();
typedef struct {
    u8 pad[0x18]; u16 u18;
    u8 pad1A[0x26]; void *u40;
} T;
void func_80138D58(T *p, u16 a1) {
    if (p->u40 && (u16)(p->u18 - 2) < 5 && (u16)(a1 - 2) < 5) {
        p->u18 = a1;
        func_8013A9F8(p->u40, a1);
    }
}
