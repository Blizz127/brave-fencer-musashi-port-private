/* Overlay range [8012DE2C,8012DEB8) from MAIN.CD member 0012.
 * SHA256(span)=e58196d7b8fa9a6e57e5524d4a887069f1cfd018a98b9bae032b8d0c49976431.
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
extern u16 D_801202A0;

u16 *func_8012DE2C(s32 arg0) {
    u16 *temp_a1;
    u16 *temp_v0;
    u16 *temp_v1;

    temp_a1 = &D_801202A0 + 0x6480;
    D_801840D4 = &D_801202A0;
    D_801840D0 = arg0;
    if (&D_801202A0 != temp_a1) {
loop_1:
        temp_v1 = D_801840D4;
        if ((*temp_v1 != 0) && (temp_v1 != arg0)) {
            D_801840D4 = (u16 *) (temp_v1 + 0x10C);
            return temp_v1;
        }
        temp_v0 = D_801840D4 + 0x10C;
        D_801840D4 = temp_v0;
        if (temp_v0 == temp_a1) {
            goto block_5;
        }
        goto loop_1;
    }
block_5:
    D_801840D4 = 0;
    return 0;
}
