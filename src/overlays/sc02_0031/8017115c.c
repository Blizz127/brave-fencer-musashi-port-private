/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017115C,8017118C).
 * Offset 0x49004 at overlay base 80128158. SHA256(span)=b0e35f1687ef926785b50d8da8b47614683298071f7b5db7d817dc4b27fb3a57.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017115c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8017118C(s32);                               /* static */
void func_80171990();                                  /* static */

void func_8017115C(s32 arg0) {
    func_80171990();
    func_8017118C(arg0);
}
