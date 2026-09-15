/* Overlay range [8012F274,8012F2E8) from MAIN.CD member 0012.
 * SHA256(span)=3dfc69ad580b53b6764763984806992d397abf51c95bada83ebe37a5ad49a6ce.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015954(void *, s32);          /* extern */
void func_80015978(s32, void *);          /* extern */
void func_8004914C(s32);                         /* extern */
void func_800491AC(s32);                         /* extern */
void func_8004945C(void *, void *, void *); /* extern */

void func_8012F274(void *arg0, s32 arg1) {
    s32 sp20;
    s32 sp18;
    s32 sp10;
    s32 temp_s0;

    func_80015978(arg1, &sp10);
    temp_s0 = M2C_FIELD(arg0, s32 *, 0x20) + 0x34;
    func_8004914C(temp_s0);
    func_800491AC(temp_s0);
    func_8004945C(&sp10, &sp18, &sp20);
    func_80015954(&sp18, arg1);
}
