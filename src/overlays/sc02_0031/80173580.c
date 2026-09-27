/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173580,801735B8).
 * Offset 0x4B428 at overlay base 80128158. SHA256(span)=06d558c78be895d0f91a191feb6311a1c4164e6b913b18da08c24375a420e65f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173580.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80147060();                                  /* static */
void func_80171A1C(s32);                               /* static */
void func_801735B8(s32);                               /* static */

void func_80173580(s32 arg0) {
    func_80147060();
    func_80171A1C(arg0);
    func_801735B8(arg0);
}
