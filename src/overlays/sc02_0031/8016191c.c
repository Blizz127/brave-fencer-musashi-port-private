/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016191C,8016197C).
 * Offset 0x397C4 at overlay base 80128158. SHA256(span)=8ff1239c29cabd0d23c36ba4db1f419c75c1f328568599c27d0a8542e696bf44.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016191c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8014C010();
s32 func_8016191C(void *p, s32 a1) {
    if (a1 & 1) {
        func_8014C010(p, 1);
        return 1;
    }
    if (a1 & 0x4000) {
        func_8014C010(p, 1);
        return 2;
    }
    if (a1 & 0x2000) {
        func_8014C010(p, 1);
        return 4;
    }
    return 0;
}
