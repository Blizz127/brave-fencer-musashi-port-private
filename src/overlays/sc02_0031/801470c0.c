/* Complete SC02 retail span [801470C0,80147118).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


void func_801470C0(s32 a0) {
    s32 a1 = *(s32 *)(a0 + 0x20);

    if (a1 != 0) {
        if ((*(u8 *)(a0 + 0x221) | *(u8 *)(a0 + 0x220) | *(u8 *)(a0 + 0x222)) != 0) {
            *(s32 *)(a1 + 0x4) |= 0x80000000;
        } else {
            *(s32 *)(a1 + 0x4) &= 0x7FFFFFFF;
        }
    }
}
