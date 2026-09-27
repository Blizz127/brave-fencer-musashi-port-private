/* Overlay range [8013B83C,8013B9F0) from MAIN.CD member 0012.
 * SHA256(span)=b1f5a56416783ae456759347911bc8fab8633d7799e4b30cb296d8ab68dabbe9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80052D90(s32, s32 (*)());                        /* extern */
void func_8013BC64();                                  /* extern */
extern s32 D_80185B58;
extern s32 D_80185B64;
extern s32 D_80185B70;
extern s32 D_80185BF4;
extern s32 D_80185BF8;
extern s32 D_80185BFC;
extern s32 D_80185C10;
extern s32 D_80185C20;
extern s32 D_80185C70;
extern s32 D_80185C74;
void func_8013B9F0();                                  /* static */
extern s32 *D_80185B5C;

void func_8013B83C(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp10;

    D_80185C10 = 0;
    D_80185BFC = 0;
    D_80185BF8 = 0;
    D_80185BF4 = 0;
    func_80052D90(0, D_80185C20);
    if (arg0 == 0) {
        func_8013BC64();
        return;
    }
    D_80185C70 = (s32) (arg2 + 0x1F4);
    D_80185C74 = arg2;
    sp10 = 0;
loop_4:
    if (sp10 < 4) {
        *(D_80185B58 + (sp10 * 0x1C)) = 0;
        ((sp10 * 0x1C) + D_80185B58)->unk8 = 0x6000;
        ((sp10 * 0x1C) + D_80185B58)->unk6 = 0x6000;
        *(&D_80185B5C + (sp10 * 0x1C)) = 0x6000;
        *(D_80185B64 + (sp10 * 0x1C)) = 0x100;
        *(D_80185B70 + (sp10 * 0x1C)) = 0;
        sp10 += 1;
        goto loop_4;
    }
    func_8013B9F0();
}
