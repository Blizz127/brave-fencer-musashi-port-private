/* SC02 resident retail span [8016F14C,8016F1AC). Offset 0x46FF4 at base 80128158.
 * SHA256(span)=8a876cbf4d0099edacc4abdecaf9b07db5880e08c345237e2b3bf09d9628ddb2.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * the C is the Druthulu shared/ov func_8016F14C shape (h_exact edf31e68) with its func_80148634 extern; oracle MATCH 24/24.
 * Not MAIN10.
 */
#include "psx_types.h"

extern void func_80148634(void *a0);

void func_8016F14C(void *a0) {
    s32 v1 = *(s32 *)((u8 *)a0 + 0x1F8);
    s32 fp = v1 & 0x80FFFFFF;
    if (v1 != 0) {
        if (v1 & 0x1000000) {
            func_80148634(a0);
        }
        ((void (*)(void *))fp)(a0);
    }
}
