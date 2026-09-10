/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F410,8016F44C).
 * Offset 0x472B8 at overlay base 80128158. SHA256(span)=162741a744d792586e8df51e0ceb394bfee8e08aa4c34629ddc1b0242f1397fc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f410.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8016F44C();
void func_8016F470();
s32 func_8016F410(void *p) {
    if (func_8016F44C(p) == 0) {
        return 0;
    }
    func_8016F470(p);
    return 1;
}
