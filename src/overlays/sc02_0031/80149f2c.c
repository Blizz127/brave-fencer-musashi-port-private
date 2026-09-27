/* Complete SC02 retail span [80149F2C,80149FA8).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 *func_80144A04(s32 *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_8016EDEC(s32 a0, s32 a1);

s32 func_80149F2C(s32 a0, s32 a1) {
    s32 *s0;

    if (*(u16 *)a1 == 0x83 || *(u16 *)a1 == 0x61) {
        s0 = func_80144A04((s32 *)a1);
        if (s0 != 0) {
            func_801599A4((void *)a0);
            func_80159B3C((void *)a0);
            func_8016EDEC((s32)s0, 0x1000000);
            return 1;
        }
    }
    return 0;
}
