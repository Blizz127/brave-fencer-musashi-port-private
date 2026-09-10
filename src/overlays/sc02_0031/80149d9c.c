/* Complete SC02 retail span [80149D9C,80149DD8).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern s32 func_80149E94(s32 a0);
extern s32 func_80149DD8(s32 a0);

s32 func_80149D9C(s32 a0) {
    if (func_80149E94(a0) != 0) {
        return 1;
    }
    return func_80149DD8(a0) != 0;
}
