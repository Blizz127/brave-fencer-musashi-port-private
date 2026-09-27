/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154150,80154190).
 * Offset 0x2BFF8 at overlay base 80128158. SHA256(span)=6922ce0c04de99e15d6cda3d691254a52d58798cf062d02f2504cb990885af0f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154150.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80154190();
typedef struct { u8 pad[0xB0]; s32 *t; s32 b4; } T;
void func_80154150(T *p, s32 a1) {
    if (p->b4 != p->t[a1]) {
        func_80154190(p, a1);
    }
}
