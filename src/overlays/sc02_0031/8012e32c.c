/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012E32C,8012E364).
 * Offset 0x61D4 at overlay base 80128158. SHA256(span)=9df247042b837a3a22caa2a21cce8809ba4fa3b98a733dd1dbfc9d79e0c69bab.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012e32c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8004914C(void *);                               /* extern */
void func_800491AC(void *);                               /* extern */
extern s32 *D_800AF648;

void func_8012E32C(void) {
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
}
