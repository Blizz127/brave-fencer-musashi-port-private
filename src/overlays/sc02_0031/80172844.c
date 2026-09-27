/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172844,8017288C).
 * Offset 0x4A6EC at overlay base 80128158. SHA256(span)=77fd1cfc8b51384056167d205cdac94ff03596e380effd720d8c3b3c25e3fb54.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172844.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80171CC4();
void func_80171A1C();
void func_80174650();
extern s16 D_80126B30;
void func_80172844(void *p) {
    if (func_80171CC4(p, &D_80126B30)) {
        func_80171A1C(p);
        func_80174650(p);
    }
}
