/* Overlay range [80178BF8,80178CBC) from MAIN.CD member 0012.
 * SHA256(span)=433b3cd99c3d18fb5819b8a31ab8cb82be850624b0bed81241fe36f47aeffbd4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016714(void *, s32);                            /* extern */
extern s32 D_8018533E;
extern s32 D_80185340;
extern s32 D_80185344;
extern s32 D_80185348;
extern s32 D_80185350;
extern s32 D_80185354;
extern s32 D_80185358;
extern s32 D_8018535C;
extern s32 D_80185360;
extern s32 D_80185368;
extern s32 D_801853B8;
extern s32 D_80185B24;
void func_8017B1D8();                                  /* static */
extern s32 *D_80185BD8;
extern s16 D_80185C7C;

void func_80178BF8(void) {
    s32 (*var_a0)();
    s32 (*var_v0)();
    s32 var_v1;
    s32 var_v1_2;

    var_v1 = 9;
    var_a0 = D_801853B8;
    D_80185C7C = 0;
    D_80185350 = 0;
    D_80185360 = 0;
    D_8018535C = 0;
    D_80185358 = 0;
    D_80185354 = 0;
    D_80185B24 = 1;
    D_80185368 = 0;
    D_80185348 = 0;
    do {
        *var_a0 = 0;
        var_v1 -= 1;
        var_a0 -= 4;
    } while (var_v1 >= 0);
    var_v1_2 = 0x1FF;
    var_v0 = D_8018533E;
    do {
        *var_v0 = 0;
        var_v1_2 -= 1;
        var_v0 -= 2;
    } while (var_v1_2 >= 0);
    D_80185340 = 0;
    D_80185344 = 0;
    func_80016714(&D_80185BD8, 0x14);
    func_8017B1D8();
}
