/* Main-exec range [8002FA3C,8002FAE0) from the SLUS executable.
 * SHA256(span)=f29a61662d929a74181501ae5a9b69d24a7cfb1ddadb003e398f2b8abf5ce798.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003EDE8(s32, s16, s16);                       /* static */
extern s16 D_800760E4;
extern u16 D_800760E8;
extern s16 D_800760EC;
extern s32 D_800A4F24;

void func_8002FA3C(void) {
    s16 temp_a1;
    u16 temp_v0;

    temp_v0 = D_800760E8 + 1;
    D_800760E8 = temp_v0;
    if ((s16) temp_v0 < 0x10) {
        if (D_800760EC < D_800760E4) {
            temp_a1 = D_800760E4 - D_800760EC;
            D_800760E4 = temp_a1;
            func_8003EDE8(0, temp_a1, temp_a1);
            return;
        }
        goto block_4;
    }
block_4:
    func_8003EDE8(0, 0, 0);
    D_800A4F24 = 0;
}
