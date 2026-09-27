/* Complete SC02 retail span [8012AD44,8012AD50).
 * Matched C: SC02 twin of main_0012/8012ad44 (local leaf word export).
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

void func_8012AD44(s32 obj, s16 arg1) {
    *(s16 *)(obj + 0x2) = arg1;
    *(s16 *)(obj + 0x34) = 0;
}
