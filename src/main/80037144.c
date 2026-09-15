/* Exact retail word export for [80037144,80037334); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800652F0;
extern s32 D_80065438;
void func_800415A8(s16, s32, s32);                       /* static */
extern void *D_80076228;
extern void *D_8007622C;
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
extern s32 D_800A469C;
extern s16 D_800A46A0;
extern s16 D_800A46A2;
extern u8 D_800A46B0;
extern s32 *D_800BA320;

void func_80037144(s32 arg0) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v0;
    s32 var_s0;
    s32 var_v0;
    s32 var_v1;

    var_s0 = 0;
    var_v1 = 0;
loop_1:
    var_v0 = var_s0 < 5;
    if (*(&D_80076251 + var_v1) != 0) {
        var_s0 += 1;
        var_v1 += 0x10;
        if (var_s0 >= 5) {
            var_v0 = var_s0 < 5;
        } else {
            goto loop_1;
        }
    }
    temp_a1 = var_s0 * 0x10;
    if (var_v0 != 0) {
        *(&D_80076244 + temp_a1) = &D_800BA320;
        *(&D_80076248 + temp_a1) = arg0 | 0x2000;
        temp_a0 = arg0 * 2;
        *(&D_80076250 + temp_a1) = 0;
        *(&D_80076251 + temp_a1) = 1;
        *(&D_80076252 + temp_a1) = 4;
        temp_v0 = *(D_800652F0 + (*(D_80065438 + temp_a0) * 4));
        D_800A469C = temp_v0;
        *(&D_8007624C + temp_a1) = temp_v0;
        if (D_800A46B0 == 0) {
            if (D_800A46A0 == (*(D_80065438 + temp_a0) | 0x4000)) {
                *(&D_80076248 + temp_a1) = *(&D_80076248 + temp_a1) | 0x1000;
            } else {
                D_800A46B0 = 1;
                goto block_10;
            }
        } else {
block_10:
            if (D_800A46A2 >= 0) {
                func_800415A8(D_800A46A2, temp_a1, 1);
                D_800A46A2 = -1;
            }
        }
        if (var_s0 == 0) {
            D_8007622C = &D_800BA320;
            D_80076228 = &D_800BA320;
            D_80076240 = 0;
            D_80076243 = 1;
            D_80076242 = 0;
            D_80076294 = 0;
            D_80076238 = *(&D_800A463C + (4 * 0x18));
        }
    }
    D_8007629C = 0;
}
