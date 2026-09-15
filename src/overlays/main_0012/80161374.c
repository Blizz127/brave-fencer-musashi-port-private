/* Overlay range [80161374,80161418) from MAIN.CD member 0012.
 * SHA256(span)=445f36f31057cb527e0a1b6789dd349899c37bf3c7e988eb6b8c17bb653e83f4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015954(void *, void *);              /* extern */
void func_801599A4(void *);                      /* static */
void func_8015BDD0(void *);                      /* static */
void func_8015BF48(void *);                      /* static */
extern s32 D_801152BC;

s32 func_80161374(void *arg0, s32 arg1) {
    if ((arg1 == 0) || (arg1 == 0x8000)) {
        func_801599A4(arg0);
        func_8015BDD0(arg0);
        return 1;
    }
    if (arg1 & 0x4000) {
        if ((D_801152BC != 0) || (M2C_FIELD(arg0, s16 *, 0xA) >= M2C_FIELD(arg0, s16 *, 0x8A))) {
            func_801599A4(arg0);
            func_8015BF48(arg0);
            return 1;
        }
        func_80015954(arg0 + 0x88, arg0 + 4);
        /* Duplicate return node #8. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
