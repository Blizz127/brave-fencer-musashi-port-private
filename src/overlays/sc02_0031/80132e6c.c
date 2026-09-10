/* SC02.CD FILE_031 / ov_SC02_031 retail span [80132E6C,80132EC4).
 * Offset 0xAD14 at overlay base 80128158. SHA256(span)=de4161c97551428100a8d63a3bfd6b608856cc2ad6634d558675644b4acb67b5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80132e6c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80049324();
extern s16 D_80126CAC;
extern s16 D_80126CB0;
typedef struct { s32 x, y, z; } V;
s32 func_80132E6C(s16 *p) {
    V in, out;
    in.x = p[3] - D_80126CAC;
    in.y = 0;
    in.z = p[7] - D_80126CB0;
    func_80049324(&in, &out);
    return out.x + out.z;
}
