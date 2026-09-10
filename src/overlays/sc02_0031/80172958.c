/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172958,801729A8).
 * Offset 0x4A800 at overlay base 80128158. SHA256(span)=c94740b41d1a3ec4fefbbd9d5f76f52f2f58c87e818d150df36f9e422f7df5d1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172958.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80171D1C();
void func_80171A1C();
void func_80174650();
extern s16 D_80126B30;
extern u8 D_80126B36;
void func_80172958(void *p) {
    if (func_80171D1C(p, &D_80126B30, D_80126B36)) {
        func_80171A1C(p);
        func_80174650(p);
    }
}
