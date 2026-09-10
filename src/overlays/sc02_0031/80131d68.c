/* SC02.CD FILE_031 / ov_SC02_031 retail span [80131D68,80131E00).
 * Offset 0x9C10 at overlay base 80128158. SHA256(span)=1ffe687b232fcef7e000113b5b2889d08bdba073e5414a43b0008d35866c661d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80131d68.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80131E00();
s32 func_80131CA8();
void func_8002A04C();
void func_8012C218();
typedef struct { u8 pad[0x78]; s32 u78; } T;
s32 func_80131D68(T *p, s32 a1) {
    a1 = (u8)a1;
    if (a1 == 2 || a1 == 0x1B) {
        func_80131E00(p, 0x12);
        return 1;
    }
    if (a1 == 0x1A || a1 == 0x1C) {
        if (func_80131CA8(p, 0x11)) {
            return 1;
        }
        if (p->u78) {
            func_8002A04C(p);
        }
        func_8012C218(p);
        return 1;
    }
    return 0;
}
