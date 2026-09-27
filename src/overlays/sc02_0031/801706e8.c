/* SC02.CD FILE_031 / ov_SC02_031 retail span [801706E8,80170718).
 * Offset 0x48590 at overlay base 80128158. SHA256(span)=07b1905e832db9d12ec8ccf6418076b188b6dec310210fbab7222f7a1835633e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801706e8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80170718(s32);                               /* static */
void func_80171990();                                  /* static */

void func_801706E8(s32 arg0) {
    func_80171990();
    func_80170718(arg0);
}
