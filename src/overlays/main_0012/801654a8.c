/* Overlay range [801654A8,80165580) from MAIN.CD member 0012.
 * SHA256(span)=4aa3a29f52e7998de00efd8f9f8d90bf1807be438b0108ab9287cac1323ad0ba.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800CAE0C(void *);                            /* extern */
extern s32 D_80180FE4;
s32 func_80165658(u8);                              /* static */
extern s32 D_80078E78;
extern u8 D_80078EC1;

void func_801654A8(void *arg0) {
    u16 temp_v1;
    u16 temp_v1_2;

    temp_v1 = arg0->unk0;
    if (temp_v1 != 0x16) {
        if ((temp_v1 != 0x1A) && !(arg0->unk1F8 & 0x80FFFFFF) && (func_80165658(D_80078EC1) & 0x80)) {
            *(D_80180FE4 + ((D_80078EC1 & 0x7F) * 4))(arg0);
        }
        temp_v1_2 = arg0->unk0;
        if ((temp_v1_2 != 0x16) && (temp_v1_2 != 0x1A) && (D_80078E78.unk49 == 0x19)) {
            func_800CAE0C(arg0);
        }
    }
}
