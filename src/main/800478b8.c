/* Exact retail word export for [800478B8,80047948); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8006C0A8;
extern s32 D_8006D0A8;

s16 func_800478B8(s32 arg0) {
    if (arg0 < 0x801) {
        if (arg0 < 0x401) {
            return *(D_8006D0A8 + (arg0 * 2));
        }
        return *(D_8006D0A8 + ((0x800 - arg0) * 2));
    }
    if (arg0 >= 0xC01) {
        return -*(D_8006D0A8 + ((0x1000 - arg0) * 2));
    }
    return -D_8006C0A8[arg0];
}
