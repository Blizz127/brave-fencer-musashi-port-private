/* Overlay range [80147364,801473DC) from MAIN.CD member 0012.
 * SHA256(span)=5d196618d420b92a4e2ac92a5dcc247ca2d952cde79d22c290657d9a57e5cf57.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015978(void *, void *);                       /* extern */
void func_8002D4C8(s32, s32);                          /* extern */
void func_8012E5CC(void *, s32, s32);                     /* static */
extern s16 D_800B9A08;
extern s32 *D_80126B58;

void func_80147364(s32 arg0, s32 arg1) {
    s32 sp10;
    if (D_800B9A08 == 0x308D) {
        func_80015978(&D_80126B58 + 4, &sp10);
        func_8012E5CC(&sp10, arg0 & 0xFFFF, arg1 & 0xFFFF);
        return;
    }
    func_8002D4C8(arg0 & 0xFFFF, arg1 & 0xFFFF);
}
