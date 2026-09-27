/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154B98,80154BC8).
 * Offset 0x2CA40 at overlay base 80128158. SHA256(span)=04661d0bca0f01017a381e98080aaa60984b298e71b13c7a8a2dbe5598fd89f5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154b98.c (m2c-derived, oracle MATCH); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80154BC8();
typedef struct { u8 pad[0xD0]; s32 d0; } T;
void func_80154B98(T *p, s32 a1, s32 a2) {
    if (p->d0 != a1) {
        func_80154BC8(p, a1, a2);
    }
}
