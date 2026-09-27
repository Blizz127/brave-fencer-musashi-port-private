/* SC02.CD FILE_031 / ov_SC02_031 retail span [801687CC,80168828).
 * Offset 0x40674 at overlay base 80128158. SHA256(span)=128ff978787602976fddfd94cba6a0c4013766d76c0f64b881d7f2cb63c36286.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801687cc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80168828();
void func_80146C3C();
typedef struct { u8 pad[0x1C]; s32 t; } T;
void func_801687CC(T *p) {
    if (p->t < 3) {
        func_80168828(p);
        p->t++;
    } else {
        func_80146C3C(p);
    }
}
