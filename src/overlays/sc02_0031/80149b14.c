/* Complete SC02 retail span [80149B14,80149B54).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern void func_8015DAC4(s32 *a0);
extern void func_8015554C(s32 *a0);

void func_80149B14(s32 *a0) {
    if (*(s32 *)((s32)a0 + 0x178) != 0) {
        func_8015DAC4(a0);
    } else {
        func_8015554C(a0);
    }
}
