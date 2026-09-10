/* SC02.CD FILE_031 / ov_SC02_031 retail span [801684B4,80168540).
 * Offset 0x4035C at overlay base 80128158. SHA256(span)=35d6589cf5b3093a957c490e2f7979ee6f482c42a93b8f93f4f7f0ebdc793432.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801684b4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80146C3C();
void func_80166994();
typedef struct Inner { u8 pad[0x44]; s32 flags; } Inner;
typedef struct {
    u8 pad[2]; u16 u2; u8 pad4[0x26]; s16 u2A, u2C;
    u8 pad2E[6]; Inner *p34;
} T;
void func_801684B4(T *p) {
    if ((p->p34->flags & 2) == 0) {
        func_80146C3C(p);
    } else {
        p->u2A--;
        if (p->u2A == 0) {
            func_80166994(p, 0, 2, 0);
            p->u2++;
        }
    }
}
