/* Overlay range [80155D70,80155E30) from MAIN.CD member 0012.
 * SHA256(span)=0acbe3f37a3df0977580619146cf3e6d3b96b13a150e4d3f2a69217d929f94f0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_801487F4();                                /* static */
s32 func_8014CC28(void *);                          /* static */
s32 func_8014F3E8(void *);                          /* static */
void func_801599A4(void *);                      /* static */
void func_80159B3C(void *);                      /* static */
void func_8015BDD0(void *);                      /* static */
void func_8015E880(void *);                      /* static */

void func_80155D70(void *arg0) {
    s32 temp_s1;

    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 2);
    if (M2C_FIELD(arg0, u16 *, 0xB8) == 0x8000) {
        if (func_801487F4() & 0x80) {
            func_801599A4(arg0);
            func_8015E880(arg0);
            return;
        }
        func_801599A4(arg0);
        func_80159B3C(arg0);
        return;
    }
    temp_s1 = func_8014CC28(arg0);
    if ((func_8014F3E8(arg0) == 0) && (temp_s1 == 0)) {
        func_801599A4(arg0);
        func_8015BDD0(arg0);
    }
}
