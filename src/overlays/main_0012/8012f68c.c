/* Overlay range [8012F68C,8012F75C) from MAIN.CD member 0012.
 * SHA256(span)=8cd7db8e21707be4d6b1520ec687a39864a94b9621eec2e6a8fce72bab4eadde.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* Verified byte-exact against retail by tools/match_function.py (52/52 words at 0x8012F68C). Types and signatures are whatever reproduces the bytes; they are not evidence of the original declaration. */

s32 func_8012BEE8(void *);                          /* static */
s32 func_8012CBCC(void *);                            /* static */
void func_80131C78(void *);                      /* static */
void func_80131CA8(void *, s32);             /* static */
void func_80131E00(void *, s32);             /* static */

void func_8012F68C(void *arg0) {
    s32 var_s1;
    s32 var_v0;

    var_s1 = 0;
    if (!(M2C_FIELD(arg0, s32 *, 0xC4) & 2) && (M2C_FIELD(arg0, s32 *, 0xB4) & 1)) {
        if ((func_8012CBCC(arg0) & 0xFF) == 2) {
            func_80131E00(arg0, 0x12);
            return;
        }
        if (M2C_FIELD(arg0, u8 *, 0xC2) != 0) {
            var_v0 = func_8012BEE8(arg0);
        } else {
            var_v0 = M2C_FIELD(arg0, u16 *, 0x72) & 0x4000;
        }
        if (var_v0 != 0) {
            var_s1 = 1;
        }
        if (var_s1 != 0) {
            func_80131C78(arg0);
        }
        goto block_12;
    }
block_12:
    func_80131CA8(arg0, 5);
}
