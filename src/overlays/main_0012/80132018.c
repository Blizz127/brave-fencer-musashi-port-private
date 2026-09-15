/* Overlay range [80132018,801320D0) from MAIN.CD member 0012.
 * SHA256(span)=e3b7c919086f00af129dabf9e1ddb3d20b6101ad0e2aa808ccd1f13ef5d29531.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001C214(s32, s32);                            /* extern */
extern s32 D_8017E8A8;
extern s32 D_8017E8AC;
s32 func_8012C1B8();                                /* static */
void func_8012CAE4(void *);                            /* static */

void func_80132018(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_8012C1B8();
    arg0->unk20 = temp_v0;
    if (temp_v0 == 0) {
        func_8012CAE4(arg0);
        return;
    }
    func_8001C214(temp_v0, 0);
    arg0->unk5C = 0x80;
    arg0->unk2 = (u16) (arg0->unk2 + 1);
    arg0->unk58 = (void *) (((arg0->unk70 & 0xFFF) * 0x14) + D_8017E8AC);
    arg0->unkFC = (s16) (((u16) arg0->unk70 >> 0xC) << 9);
    arg0->unkDC = (s32) *(D_8017E8A8 + ((arg0->unk70 & 0xFFF) * 0x14));
}
