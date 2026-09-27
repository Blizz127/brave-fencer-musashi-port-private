/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151204,80151238).
 * Offset 0x290AC at overlay base 80128158. SHA256(span)=71c8d0a813a659d45f5772cc159d9af1c40818425484a65d3fddae0a269e2877.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151204.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8014ACE8();
void func_80151204(void *p, s32 a1) {
    if (a1 && a1 != 0x3E8) {
        func_8014ACE8(p, 1, a1 & 0x7FFF);
    }
}
