/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171CC4,80171D1C).
 * Offset 0x49B6C at overlay base 80128158. SHA256(span)=77406bf035774a6a3aac772b047585e40e0c431fed121ceb65adf236d596a73c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171cc4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80171D78();
s32 func_8017250C();
void func_80146D90();
s32 func_80171CC4(void *p, void *q) {
    s32 v = func_80171D78(p, q);
    if (func_8017250C(p, q)) {
        func_80146D90(p);
    }
    return v;
}
