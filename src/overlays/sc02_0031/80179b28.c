/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179B28,80179B74).
 * Offset 0x519D0 at overlay base 80128158. SHA256(span)=22c55799b84cd85e387a220afb6edb591027ca4dd0663d99df955f94d27e51c6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179b28.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80139914();
typedef struct { void *u0; s16 u4; } T;
void func_80179B28(T *p) {
    if (p && p->u0 && p->u4 && p->u4 != 0xE) {
        func_80139914(p);
    }
}
