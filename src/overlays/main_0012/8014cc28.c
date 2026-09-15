/* Overlay range [8014CC28,8014CCB4) from MAIN.CD member 0012.
 * SHA256(span)=6ffe0d77d16928966cd3723be0029a3d5776a5f6abea429e18262aeb4dc8a01e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8014CCB4();                            /* static */
void func_8014D04C();                            /* static */
void func_8014D3E0();                            /* static */

void func_8014CC28(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x44) < 0) {
        if (M2C_FIELD(arg0, s16 *, 0xA) != M2C_FIELD(arg0, s16 *, 0x8A)) {
            func_8014D3E0();
            return;
        }
        if ((M2C_FIELD(arg0, s16 *, 6) != M2C_FIELD(arg0, s16 *, 0x88)) || (M2C_FIELD(arg0, s16 *, 0xE) != M2C_FIELD(arg0, s16 *, 0x8C))) {
            func_8014D04C();
            return;
        }
        goto block_6;
    }
block_6:
    func_8014CCB4();
}
