/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173948,80173980).
 * Offset 0x4B7F0 at overlay base 80128158. SHA256(span)=ecde7676b4da16f5d31f557b05fe027f73a5ac780fa8a0240ea6c038460e71d2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173948.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80147060();                                  /* static */
void func_80171A1C(s32);                               /* static */
void func_80173980(s32);                               /* static */

void func_80173948(s32 arg0) {
    func_80147060();
    func_80171A1C(arg0);
    func_80173980(arg0);
}
