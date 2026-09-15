/* Overlay range [8012DDA4,8012DE2C) from MAIN.CD member 0012.
 * SHA256(span)=8e0d36f684ae0058590ef139652bdd4047a1878eae9b012e07e92f16eac65cd9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_801840D0;
extern s32 D_801840D4;
extern s32 *D_80126720;

u16 *func_8012DDA4(void) {
    u16 *temp_v0;
    u16 *temp_v1;

    if (D_801840D4 != &D_80126720) {
loop_2:
        temp_v1 = D_801840D4;
        if ((*temp_v1 != 0) && (temp_v1 != D_801840D0)) {
            D_801840D4 = (u16 *) (temp_v1 + 0x10C);
            return temp_v1;
        }
        temp_v0 = D_801840D4 + 0x10C;
        D_801840D4 = temp_v0;
        if (temp_v0 == &D_80126720) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    D_801840D4 = 0;
    return 0;
}
