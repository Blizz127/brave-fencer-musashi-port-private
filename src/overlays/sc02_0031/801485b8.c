/* Complete SC02 retail span [801485B8,80148634).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


void func_801485B8(s32 arg0, s32 arg1, s32 arg2) {
    *(s16 *)(arg1 + 0) = (s16)(s8)*(u8 *)(arg0 + 0);
    *(s16 *)(arg1 + 2) = (s16)(s8)*(u8 *)(arg0 + 1);
    *(s16 *)(arg1 + 4) = (s16)(s8)*(u8 *)(arg0 + 2);
    *(s16 *)(arg2 + 0) = (s16)(s8)*(u8 *)(arg0 + 3);
    *(s16 *)(arg2 + 2) = (s16)(s8)*(u8 *)(arg0 + 4);
    *(s16 *)(arg2 + 4) = (s16)(s8)*(u8 *)(arg0 + 5);
}

