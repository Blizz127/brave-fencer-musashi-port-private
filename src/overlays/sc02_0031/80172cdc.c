/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172CDC,80172D14).
 * Offset 0x4AB84 at overlay base 80128158. SHA256(span)=8cebc1f3a87d9f1543ceea76312b4758daf47f7d5eb50483a0ce05e137cbabfb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172cdc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80147060();                                  /* static */
void func_80171A1C(s32);                               /* static */
void func_80172D14(s32);                               /* static */

void func_80172CDC(s32 arg0) {
    func_80147060();
    func_80171A1C(arg0);
    func_80172D14(arg0);
}
