/* Exact retail word export [800468FC,80046980); verified against pinned EXE and asm. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CCA8;
extern s32 *D_8006CFE8;
extern s32 *D_8006CFF4;
void func_800435B4();                                 /* static */
void func_800439D4();                                 /* static */
void func_80046994();                                 /* static */
void func_800469A8();                                 /* static */
void func_8005CF08();                                  /* static */
void func_8005CF18();                                  /* static */

void func_800468FC(void) {
    func_8005CF08();
    if (D_8006CCA8 == 1) {
        func_800469A8(0);
        func_80046994(0);
    } else {
        func_800439D4(0);
        func_800435B4(0);
    }
    *D_8006CFE8 = 0;
    *D_8006CFF4 = 0;
    func_8005CF18();
}
