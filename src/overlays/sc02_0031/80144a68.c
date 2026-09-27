/* Complete SC02 retail span [80144A68,80144A90).
 * Matched C: Druthulu shared ov/func_80144A68.h (local leaf word export).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern void func_8012AD44(s32 *obj, s16 a1);

void func_80144A68(s32 *obj) {
    *(s16 *)obj = 0xC6;
    func_8012AD44(obj, 0);
}
