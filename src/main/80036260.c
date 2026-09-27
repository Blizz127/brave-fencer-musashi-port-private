/* Main-exec range [80036260,800363CC) from the SLUS executable.
 * SHA256(span)=5a6f944b3935a5be66a54a69bb43b167e4c76d00dfd0a8e1336b67b822e73718.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006AF00;
void func_80037334();                                  /* static */
void func_800415A8(s16);                               /* static */
s32 func_8004355C(s32, void *);                          /* static */
extern u8 D_8006AEF4;
extern s16 D_800A46A2;
extern s8 D_800A46B0;
extern u16 D_800A4E8E;
extern s32 D_800A6544;

s32 func_80036260(void) {
    s32 sp10;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;

    func_80037334();
    D_8006AEF4 &= 0xFD;
    D_800A4E8E &= 0xFFDF;
    if ((D_8006AF00 != 0) && ((u32) D_8006AF00 < 0x12U)) {
        switch (D_8006AF00) {
        case 0:
        case 1:
        case 2:
            break;
        }
    }
    temp_v0 = D_800A6544 - 1;
    if ((D_800A6544 == 0) || (D_800A6544 = temp_v0, (temp_v0 == 0)) || (temp_v0_2 = func_8004355C(1, &sp10), (temp_v0_2 == 5)) || (var_v0 = 0, (temp_v0_2 == 2))) {
        D_8006AF00 = 0U;
        D_800A6544 = 0;
        var_v0 = 1;
        if (D_800A46A2 >= 0) {
            func_800415A8(D_800A46A2);
            D_800A46A2 = -1;
            D_800A46B0 = 1;
            var_v0 = 1;
        }
    }
    return var_v0;
}
