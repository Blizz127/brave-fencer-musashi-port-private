/* Overlay range [80139E84,80139F0C) from MAIN.CD member 0012.
 * SHA256(span)=755e076bd7dfd030084960c123a8c8a60d6dc324ae5870392f0723621c25e0b9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80139A8C(void *);                      /* static */
void func_80139B18(void *);                      /* static */

void func_80139E84(void *arg0) {
    s32 temp_v1;

    if (M2C_FIELD(arg0, u16 *, 0xE) == 0) {
        M2C_FIELD(arg0, s16 *, 4) = 2;
    } else {
        func_80139A8C(arg0);
        if (M2C_FIELD(arg0, s32 *, 8) & 0x80020) {
            temp_v1 = M2C_FIELD(arg0, s32 *, 8);
            M2C_FIELD(arg0, s16 *, 4) = 2;
            M2C_FIELD(arg0, u16 *, 0xE) = 0U;
            if (!(temp_v1 & 0x20000)) {
                M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_v1 & ~0x20);
            }
        }
    }
    func_80139B18(arg0);
}
