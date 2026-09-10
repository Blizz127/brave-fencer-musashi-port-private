/* Complete SC02 retail span [80146994,801469C8).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

s32 func_80146994(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80146A6C(arg0 & 0xFFFF, (void *)arg1, 0, 0, 0, arg2, arg3);
}
