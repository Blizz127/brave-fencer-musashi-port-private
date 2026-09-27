/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173824,8017385C).
 * Offset 0x4B6CC at overlay base 80128158. SHA256(span)=3aa45719a2f475e91b5bb806e2bb80bf831b556ff401261266835f74c8256b3e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173824.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80147060();                                  /* static */
void func_80171A1C(s32);                               /* static */
void func_8017385C(s32);                               /* static */

void func_80173824(s32 arg0) {
    func_80147060();
    func_80171A1C(arg0);
    func_8017385C(arg0);
}
