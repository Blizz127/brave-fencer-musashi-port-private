/* SC02.CD FILE_031 / ov_SC02_031 retail span [801741EC,80174274).
 * Offset 0x4C094 at overlay base 80128158. SHA256(span)=b94d480e0f1c0f382cab6c3c92b01652c64b71bd728ec25c3458b35cd0a32b30.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801741ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80012B04();
void func_80171A1C();
void func_80174650();
extern s16 D_80126B3C;
extern s16 D_8011F9C8;
typedef struct Inner { u8 pad[0x12]; s16 a; } Inner;
typedef struct { u8 pad[0x20]; Inner *inner; } T;
void func_801741EC(T *p) {
    s32 d = func_80012B04(p->inner->a, D_80126B3C, 4);
    if ((s16)d == 0) {
        D_8011F9C8 = 1;
        func_80171A1C(p);
        func_80174650(p);
    }
    p->inner->a = (p->inner->a + d) & 0xFFF;
}
