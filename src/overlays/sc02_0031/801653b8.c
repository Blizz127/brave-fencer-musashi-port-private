/* SC02.CD FILE_031 / ov_SC02_031 retail span [801653B8,801653F4).
 * Offset 0x3D260 at overlay base 80128158. SHA256(span)=bf79dcc2cb9cdd0d8a86e1757fe04ad7c3ca7b0465f448080e6920eb645c9c8d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801653b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80147078(s32, s32);                            /* static */
void func_801653F4();                                  /* static */
void func_80165580(s32);                               /* static */

void func_801653B8(s32 arg0) {
    func_801653F4();
    func_80147078(arg0, 0x17);
    func_80165580(arg0);
}
