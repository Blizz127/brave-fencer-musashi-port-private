/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B864,8012B8A4).
 * Offset 0x370C at overlay base 80128158. SHA256(span)=4e95c602b3faeacfa74dbd35b3528d2d312cf9062ed781abf071a3af63ddff3a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b864.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s16 D_80126CB8;
extern s16 D_80126CB4;
s32 func_8004CFEC();
s32 func_8012B864(s16 *p) {
    return (func_8004CFEC(p[7] - D_80126CB8, D_80126CB4 - p[3]) - 0x400) & 0xFFF;
}
