/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E5F4,8016E688).
 * Offset 0x4649C at overlay base 80128158. SHA256(span)=a5c286cafcde5def7195098258aee909d554c0c7fe6e69e2384ce1f0f86dbe2e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e5f4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80015978();
s32 func_8012EFB8();
void func_80146C3C();
void func_80015954();
typedef struct { u8 pad[2]; u16 u2; u8 pad4[0xC]; s16 u10, u12, u14, u16; } T;
void func_8016E5F4(T *p) {
    s16 tmp[4];
    func_80015978((u8 *)p + 4, tmp);
    if (func_8012EFB8(tmp, tmp) & ~0x1000) {
        func_80146C3C(p);
    } else {
        func_80015954(tmp, (u8 *)p + 4);
        p->u10 = 0x100;
        p->u12 = 0;
        p->u14 = 0;
        p->u16 = 0x80;
        p->u2++;
    }
}
