/* Overlay range [80171D78,80171E08) from MAIN.CD member 0012.
 * SHA256(span)=f376036dbe421c61acda785f6bfe19b54f6f71047378740419a81e6d4c52c45b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8004CFEC(s32, s32);                        /* extern */
void func_80146D90(void *);                      /* static */
void func_80171EC8(void *);                      /* static */
s32 func_8017248C();                                /* static */

s32 func_80171D78(void *arg0, void *arg1) {
    s32 temp_v0;

    temp_v0 = func_8017248C();
    if (temp_v0 == 0) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12) = (s16) ((func_8004CFEC(M2C_FIELD(arg1, s16 *, 0) - M2C_FIELD(arg0, s16 *, 6), M2C_FIELD(arg1, s16 *, 4) - M2C_FIELD(arg0, s16 *, 0xE)) + 0x800) & 0xFFF);
        func_80171EC8(arg0);
        return 0;
    }
    func_80146D90(arg0);
    return temp_v0;
}
