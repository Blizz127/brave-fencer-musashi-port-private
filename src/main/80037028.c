/* Main-exec range [80037028,80037144) from the SLUS executable.
 * SHA256(span)=21c4a123dd5d7a5c0e254f72e0cb1644f79887e32f138c4575b66b87f919bf6f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80064D49[];
extern s32 D_80076228;
extern s32 D_8007622C;
extern s32 D_80076238;
extern s16 D_80076240;
extern s8 D_80076242;
extern s8 D_80076243;
extern s32 *D_80076244;
extern s32 *D_80076248;
extern s32 *D_8007624C;
extern s32 *D_80076250;
extern s32 *D_80076251;
extern s32 *D_80076252;
extern s32 D_80076294;
extern s32 D_8007629C;
extern s32 *D_800A463C;

void func_80037028(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_v0;
    s32 var_v1;
    u8 temp_v1;

    var_a2 = 0;
    var_v1 = 0;
loop_1:
    var_v0 = var_a2 < 5;
    if (*(&D_80076251 + var_v1) != 0) {
        var_a2 += 1;
        var_v1 += 0x10;
        if (var_a2 >= 5) {
            var_v0 = var_a2 < 5;
        } else {
            goto loop_1;
        }
    }
    temp_a0 = var_a2 * 0x10;
    if (var_v0 != 0) {
        *(&D_80076251 + temp_a0) = 1;
        *(&D_80076244 + temp_a0) = arg1;
        *(&D_80076250 + temp_a0) = 0;
        *(&D_80076248 + temp_a0) = arg0;
        temp_v1 = *(D_80064D49 + (arg0 * 0xC));
        *(&D_80076252 + temp_a0) = temp_v1;
        temp_v1_2 = temp_v1 * 0x18;
        *(&D_8007624C + temp_a0) = *(&D_800A463C + temp_v1_2);
        if (var_a2 == 0) {
            D_8007622C = arg1;
            D_80076228 = arg1;
            D_80076240 = 0;
            D_80076243 = 2;
            D_80076242 = 0;
            D_80076294 = 0;
            D_80076238 = *(&D_800A463C + temp_v1_2);
        }
    }
    D_8007629C = 0;
}
