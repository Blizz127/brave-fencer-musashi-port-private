/* Overlay range [8013C360,8013C400) from MAIN.CD member 0012.
 * SHA256(span)=d316a8fa8c3995a3cc79f34cc0b1b667bcd56fbdbb5d92b9d8ab33e3a18a7921.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8013C400(void *);                      /* static */

void func_8013C360(void *arg0) {
    u32 sp4;
    void *sp0;
    void *var_a0;

    var_a0 = arg0;
    sp0 = arg0 + 0x10;
    sp4 = 0;
loop_1:
    if (sp4 < (u32) M2C_FIELD(arg0, u32 *, 8)) {
        var_a0 = M2C_FIELD(sp0, void **, 4);
        *M2C_FIELD(sp0, void ***, 0) = var_a0;
        sp0 += 0xC;
        sp4 += 1;
        goto loop_1;
    }
    func_8013C400(var_a0);
}
