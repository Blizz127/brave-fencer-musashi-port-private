/* SC02.CD FILE_031 / ov_SC02_031 retail span [80150F80,80150FB4).
 * Offset 0x28E28 at overlay base 80128158. SHA256(span)=3606cec6ba563fd077dcce7bebfd208986f08414ccb4013796c429349b48eae8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80150f80.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80151184();
extern u8 D_80078EC1;
void func_80150F80(void *p) {
    if (D_80078EC1 != 0xC) {
        func_80151184(p, 0xC007, 0x20);
    }
}
