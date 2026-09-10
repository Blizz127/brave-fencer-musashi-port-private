/* SC02.CD FILE_031 / ov_SC02_031 retail span [80159BAC,80159BE4).
 * Offset 0x31A54 at overlay base 80128158. SHA256(span)=182dba0be6450c432b3f6facb840b5a4a1c6ff110035c3ef4544486f4ba18ecd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80159bac.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80159BE4(s32);                               /* static */
s32 func_80161104();                                /* static */

void func_80159BAC(s32 arg0) {
    if (func_80161104() != 0) {
        func_80159BE4(arg0);
    }
}
