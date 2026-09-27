/* SC02.CD FILE_031 / ov_SC02_031 retail span [801608C0,80160920).
 * Offset 0x38768 at overlay base 80128158. SHA256(span)=56152d9231e39a4adecc4c1d7b35cbe1a4b1bdc07fd53798512a0199ba189807.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801608c0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801553A8();
void func_80155440();
void func_80154150();
void func_80154A74();
void func_80146CA0();
typedef struct {
    u8 pad_0[68];
    u32 flags;
} T;
void func_801608C0(T *p) {
    p->flags |= 65;
    func_801553A8(p);
    func_80155440(p);
    func_80154150(p, 36);
    func_80154A74(p, 29);
    func_80146CA0(p);
}
