/* Exact retail word export [8004657C,80046610); verified against pinned EXE and asm. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800435B4(s32 (*)());                           /* static */
void func_800435CC(s32, s8 *, s32);                        /* static */
void func_800439D4(s32 (*)());                           /* static */
extern s32 func_80046610;
extern s32 func_800469CC;
extern s32 D_800A2BA4;

void func_8004657C(s8 arg0) {
    s8 sp10;

    sp10 = arg0;
    func_800435CC(0xE, &sp10, 0);
    if (arg0 & 0x100) {
        if (arg0 & 0x20) {
            D_800A2BA4 = 0;
        } else {
            D_800A2BA4 = 1;
        }
        func_800439D4(func_800469CC);
        func_800435B4(func_80046610);
    }
    func_800435CC(0x1B, 0, 0);
}
