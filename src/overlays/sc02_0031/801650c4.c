/* SC02.CD FILE_031 / ov_SC02_031 retail span [801650C4,80165124).
 * Offset 0x3CF6C at overlay base 80128158. SHA256(span)=d8c2c623b42bece48eda3dcb7c80a4f6bcf62fad641dc2aa2c1f617f5b999df1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801650c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80162CCC();
void func_80165124();
void func_801651B8();
typedef struct { u8 pad[0x62]; s16 f; } T;
void func_801650C4(T *p) {
    p->f -= 0x10;
    if (p->f < 0) {
        func_80162CCC(p);
    } else {
        func_80165124(p);
        func_801651B8(p);
    }
}
