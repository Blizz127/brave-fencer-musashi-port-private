/* Exact retail word export for [8002EA10,8002EAB0); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002EC10();                                  /* static */
s32 func_800381E4(s16, s32);                          /* static */
s32 func_8003836C(s16);                             /* static */
void func_800383A4(s16);                               /* static */
extern s16 D_800A4E86;
extern u16 D_800A4E8E;

void func_8002EA10(void) {
    if ((D_800A4E8E & 4) && ((func_8003836C(D_800A4E86) << 0x10) != 0)) {
        if (func_800381E4(D_800A4E86, 0) != 0) {
            func_8002EC10();
            return;
        }
        func_800383A4(D_800A4E86);
        D_800A4E8E |= 0x10;
    }
}
