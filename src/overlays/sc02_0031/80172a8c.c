/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172A8C,80172ACC).
 * Offset 0x4A934 at overlay base 80128158. SHA256(span)=220ac249dce22575b48100df5135e92f63e4307622481aa699cb3436a11e9c76.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172a8c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80171CC4();
void func_80171A1C();
extern s16 D_80126B30;
void func_80172A8C(void *p) {
    if (func_80171CC4(p, &D_80126B30)) {
        func_80171A1C(p);
    }
}
