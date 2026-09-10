/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016A890,8016A8FC).
 * Offset 0x42738 at overlay base 80128158. SHA256(span)=5be8f26a04f2940d27fdb91b657b63258693b19f4069a862e6be6133806d5f14.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016a890.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8016A8FC();
void func_80146C3C();
typedef struct { u16 id; } Q;
typedef struct {
    u8 pad[0x1C]; s32 u1C;
    u8 pad20[0x14]; Q *u34;
} T;
void func_8016A890(T *p) {
    Q *q = p->u34;
    if (p->u1C < 4) {
        if (q->id == 0x14) {
            func_8016A8FC(p);
            p->u1C = p->u1C + 1;
            return;
        }
    }
    func_80146C3C(p);
}
