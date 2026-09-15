/* Overlay range [80139A8C,80139B18) from MAIN.CD member 0012.
 * SHA256(span)=080e65cd7d0afd14085b820043d7eb0f738cd0a1374122454b31784e7a03b95a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80014E80(s32, s32);                /* extern */
void func_8001931C();                            /* extern */
extern s16 D_8012752C;

void func_80139A8C(void *arg0) {
    s32 temp_v1;

    if (!(M2C_FIELD(arg0, s32 *, 8) & 0x2021) && ((func_80014E80(0, 0x20) << 0x10) != 0)) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 8) | 0x20;
        M2C_FIELD(arg0, s32 *, 8) = temp_v1;
        if (temp_v1 & 0x10000) {
            M2C_FIELD(arg0, s32 *, 8) = (s32) ((temp_v1 & 0xFFFEFFFF) | 0x20000);
            func_8001931C();
            D_8012752C = 0;
        }
    }
}
