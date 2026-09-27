/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142FFC,8014305C).
 * Offset 0x1AEA4 at overlay base 80128158. SHA256(span)=334fc89f56a4ded7c6693c0adf0a196a137b1482dd7c0faa872a736fb7ce29ab.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80142ffc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80142DB8();
s32 func_80142D38();
void func_80142BB4();
void func_80142FFC(void *p) {
    if (func_80142DB8(p) == 1) {
        func_80142BB4(p, 1, 3);
    } else if (func_80142D38(p) == 1) {
        func_80142BB4(p, 0, 3);
    }
}
