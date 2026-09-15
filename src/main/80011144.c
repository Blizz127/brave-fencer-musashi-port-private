/* Exact retail word export for [80011144,800111BC); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80072C70;
void func_80010AE0();                                 /* static */
void func_80011778();                                  /* static */
void func_80015310();                                  /* static */
s32 func_80019A24(void *, s32, s32, s32);                  /* static */
void func_8001A9F8();                                 /* static */
extern s32 *D_800AE888;

void func_80011144(void) {
    func_8001A9F8(0);
    if (func_80019A24(&D_800AE888, D_80072C70, 0, 0) != 0) {
        func_80010AE0(0x3E0);
        func_80011778();
        func_80015310();
    }
}
