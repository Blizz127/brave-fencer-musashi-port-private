/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172D14,80172D60).
 * Offset 0x4ABBC at overlay base 80128158. SHA256(span)=a8c7116186aada26e221796858ccfcb6d6c03e975ab73bd5037177c5500e5b3d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172d14.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80171AB0();
void func_80171A1C();
void func_80174650();
extern s16 D_80126B30;
void func_80172D14(void *p) {
    if ((s16)func_80171AB0(p, &D_80126B30) == 0) {
        func_80171A1C(p);
        func_80174650(p);
    }
}
