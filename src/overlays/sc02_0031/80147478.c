/* Complete SC02 retail span [80147478,801474D8).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern void func_80147514(s32 a0);
extern void func_80147628(s32 a0);

void func_80147478(s32 a0) {
    if ((*(s32 *)(a0 + 0x44) & 0x40000000) == 0) {
        func_80147514(a0);
        func_80147628(a0);
        *(s32 *)(a0 + 0x44) |= 0x40000000;
    }
}
