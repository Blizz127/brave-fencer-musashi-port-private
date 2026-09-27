/* SC02.CD FILE_031 / ov_SC02_031 retail span [8014A6C4,8014A71C).
 * Offset 0x2256C at overlay base 80128158. SHA256(span)=5066b7b0714659c6d24e7121347959f1cc0474131e077727bea2b741122af9de.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8014a6c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80029178();
typedef struct {
    u8 pad[0x44]; s32 flags;
    u8 pad48[0x176]; u8 u1BE;
} T;
s32 func_8014A6C4(T *p) {
    if ((func_80029178(0x1F) & 0xFF) == 0) {
        return 0;
    }
    if (p->flags & 4) {
        return 0;
    }
    if (p->u1BE == 0) {
        return 1;
    }
    return 0;
}
