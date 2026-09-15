/* Overlay range [80145934,80145A2C) from MAIN.CD member 0012.
 * SHA256(span)=23139b2ac6638b167b36202987026764b59fa41f869084a198084239d04cffe9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029504();                                /* extern */
void func_800D185C(s32 (*)());                           /* extern */
extern s32 D_801807BC;
extern s32 D_801807E0;
extern s32 D_80180804;
extern s32 D_80180828;
extern s32 D_8018084C;
extern s32 D_80180870;
extern s32 D_80180894;
extern s32 D_801808B8;
void func_80145B24();                                  /* static */

void func_80145934(void) {
    s32 (*var_a0)();
    s32 temp_v0;

    temp_v0 = func_80029504();
    if (temp_v0 >= 0x6A4) {
        var_a0 = D_801808B8;
    } else if (temp_v0 >= 0x5DC) {
        var_a0 = D_80180828;
    } else if (temp_v0 >= 0x578) {
        var_a0 = D_80180804;
    } else if (temp_v0 >= 0x514) {
        var_a0 = D_801807E0;
    } else if (temp_v0 >= 0x384) {
        var_a0 = D_801808B8;
    } else if (temp_v0 >= 0x258) {
        var_a0 = D_80180894;
    } else if (temp_v0 >= 0xC8) {
        var_a0 = D_80180870;
    } else {
        var_a0 = D_801807BC;
        if (temp_v0 >= 0xA) {
            var_a0 = D_8018084C;
        }
    }
    func_800D185C(var_a0);
    func_80145B24();
}
