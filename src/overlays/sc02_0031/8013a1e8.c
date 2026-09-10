/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013A1E8,8013A250).
 * Offset 0x12090 at overlay base 80128158. SHA256(span)=15048441e064dd22d8f08037c84201e88c02b152f61bb9e0fa6050c700a678fc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013a1e8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80138DB8();
void func_80138B88();
extern void *D_80127524;
typedef struct { u8 pad[8]; s32 u8; } T;
void func_8013A1E8(T *a0) {
    T *p = D_80127524;
    if (p != a0) {
        return;
    }
    if ((func_80138DB8(p, 0, 0x70) << 16) == 0) {
        if ((p->u8 & 0x800) == 0) {
            return;
        }
    }
    func_80138B88(p);
}
