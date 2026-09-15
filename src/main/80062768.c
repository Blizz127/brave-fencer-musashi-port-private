/* Main-exec range [80062768,800627D0) from the SLUS executable.
 * SHA256(span)=390a79d6b0f5b07d58195244152147f2cc8a4928ef78bfe1f4d6e36f8aca1507.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8005CE28();                                  /* static */
void func_8005CF08();                                  /* static */
void func_8005CF18();                                  /* static */
extern s32 D_80078D28;

void func_80062768(void) {
    s32 *var_v1;
    s32 var_t2;

    D_80078D28 = saved_reg_ra;
    func_8005CF08();
    var_t2 = 9;
    var_v1 = (void *(*)())0xB0()->unk16C + 0x62C;
    do {
        *var_v1 = 0;
        var_v1 += 4;
        var_t2 -= 1;
    } while (var_t2 != 0);
    func_8005CE28();
    func_8005CF18();
}
