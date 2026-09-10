/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142D38,80142DB8).
 * Offset 0x1ABE0 at overlay base 80128158. SHA256(span)=43e36762f4bbc51df4616874efd0f6a328bf8bfbfd0138311f28978c5eab5ed2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80142d38.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8012BEE8();
typedef struct Inner { u8 pad[4]; s32 u4; } Inner;
typedef struct {
    u8 pad[0x1C]; s32 u1C;
    Inner *inner;
} T;
s32 func_80142D38(T *p) {
    if (func_8012BEE8(p) == 1) {
        return 1;
    }
    if (p->u1C & 1) {
        p->inner->u4 |= 0x80000000;
    } else {
        p->inner->u4 &= 0x7FFFFFFF;
    }
    return 0;
}
