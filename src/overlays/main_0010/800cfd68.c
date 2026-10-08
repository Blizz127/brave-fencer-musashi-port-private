/* Clean-room re-derivation from the retail disassembly only (B28): MAIN.CD
 * member 0010. Looks up entry (arg0 with bits 12..15 cleared) of the table
 * 800D34AC and passes its low 12 bits to 800191D4. Returns what 800191D4
 * returns: retail leaves its v0 untouched, and the callers 800CF628 and
 * 800D1EBC test it. The earlier source fell off the end of a non-void
 * function, which the lane refuses as undefined. */
#include "psx_types.h"

extern s32 D_800D34AC[];
extern s32 func_800191D4(s32);

s32 func_800CFD68(s32 arg0) {
    return func_800191D4(D_800D34AC[arg0 & 0xFFFF0FFF] & 0xFFF);
}
