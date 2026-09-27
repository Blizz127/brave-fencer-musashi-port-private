/* Complete SC02 retail span [80144A98,80144AEC).
 * Matched C: Druthulu shared ov/func_80144A98.h (local leaf word export).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *obj);
extern void func_8001C214(s32 a0, s32 a1);

void func_80144A98(u8 *obj) {
    s32 v0;

    v0 = func_8012C1B8();
    *(s32 *)(obj + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(obj);
    } else {
        func_8001C214(v0, 0);
        *(s16 *)(obj + 0x2) = 1;
    }
}
