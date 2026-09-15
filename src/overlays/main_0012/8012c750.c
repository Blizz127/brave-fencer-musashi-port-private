/* Overlay range [8012C750,8012C820) from MAIN.CD member 0012.
 * SHA256(span)=aaba1aa9d53e7fa7446ec324df0da75cd4d454f8764899643559619e551f6757.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8012C890(u16 *, s32);                  /* static */
extern s32 *D_80120194;
extern u16 D_801202A0;

s32 func_8012C750(void *arg0) {
    u16 *var_a1;
    u16 *var_v1;
    void *temp_a1;

    if (M2C_FIELD(arg0, u16 *, 0xA) & 0x800) {
        var_a1 = &D_80120194 + 0x6480;
        if (var_a1 != &D_80120194) {
loop_2:
            if (*var_a1 != 0) {
                var_a1 -= 0x10C;
                if (var_a1 == &D_80120194) {
                    var_a1 = 0;
                } else {
                    goto loop_2;
                }
            }
        } else {
            goto block_10;
        }
    } else {
        temp_a1 = &D_80120194 + 0x658C;
        var_v1 = &D_801202A0;
        if (&D_801202A0 != temp_a1) {
loop_8:
            if (*var_v1 != 0) {
                var_v1 += 0x10C;
                if (var_v1 == temp_a1) {
                    goto block_10;
                }
                goto loop_8;
            }
            var_a1 = var_v1;
        } else {
block_10:
            var_a1 = 0;
        }
    }
    if (var_a1 == 0) {
        return 0;
    }
    M2C_FIELD(arg0, u16 *, 0xA) = (u16) (M2C_FIELD(arg0, u16 *, 0xA) | 0x8000);
    return func_8012C890(var_a1, 0);
}
