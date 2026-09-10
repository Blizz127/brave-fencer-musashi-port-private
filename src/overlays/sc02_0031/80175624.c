/* SC02.CD FILE_031 / ov_SC02_031 retail span [80175624,80175668).
 * Offset 0x4D4CC at overlay base 80128158. SHA256(span)=80adec3c14f7ae7fd59206472920535927d3f9a680b9c5f0a0c9c19cebc7e32a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80175624.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801757A0();
extern s16 D_800B9A02;
typedef struct { u8 pad[1]; u8 v; } T;
void func_80175624(T *p) {
    func_801757A0(D_800B9A02);
    p->v += 1;
}
