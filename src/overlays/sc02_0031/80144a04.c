/* Complete SC02 retail span [80144A04,80144A2C).
 * Matched C: Druthulu shared ov/func_80144A04.h (local leaf word export).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

void func_80144A04(s32 *obj) {
    void (*fp)(void);

    fp = (void (*)(void))*(s32 *)((s32)obj + 0xDC);
    fp();
}
