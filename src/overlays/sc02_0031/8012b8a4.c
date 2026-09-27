/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B8A4,8012B8E4).
 * Offset 0x374C at overlay base 80128158. SHA256(span)=cb4a6e73ab79128cda1060ab447d7bc1e6a3673df21faf2cb30a47bb8175c6fd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b8a4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s16 D_80126B66;
extern s16 D_80126B5E;
s32 func_8004CFEC();
s32 func_8012B8A4(s16 *p) {
    return (func_8004CFEC(p[7] - D_80126B66, D_80126B5E - p[3]) - 0x400) & 0xFFF;
}
