/* Complete SC02 retail span [80146C3C,80146C98).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern void func_80016714(void *a0, s32 a1);

void func_80146C3C(u8 *a0) {
    u8 *s0 = a0;
    u16 *p = *(u16 **)(s0 + 0x20);

    if (p != 0) {
        s32 a1;
        if (*p == 1) {
            a1 = 0x84;
        } else {
            a1 = 0x38;
        }
        func_80016714(p, a1);
    }
    func_80016714(s0, 0x58);
}
