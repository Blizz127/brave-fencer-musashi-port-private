/* Complete SC02 retail span [80146DB8,80146DE8).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);

void func_80146DB8(s32 *a0, s32 *a1) {
    func_80146DE8(a0, a1[0], a1[1], a1[2]);
}
