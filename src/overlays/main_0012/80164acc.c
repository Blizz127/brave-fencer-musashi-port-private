/* Overlay range [80164ACC,80164BA0) from MAIN.CD member 0012.
 * SHA256(span)=5209c8dcca8b37c7c38baffa57ab4d0084c8bbe54cb5703716248c13d1ae5e0a.
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
s32 func_8014C278(s32, u32, s32);                     /* static */
s32 func_8014C308(s32, u32, s32, s32);                  /* static */
void func_8014C3A4(s32, u32, s32, void *);                  /* static */
extern s32 *D_801202A0;
extern s32 *D_80126720;

void func_80164ACC(s32 arg0) {
    s16 sp16;
    s32 sp10;
    void *var_s0;
    u16 *var_s1;

    var_s0 = &D_801202A0;
    if ((u32) &D_801202A0 < (u32) (&D_801202A0 + 0x6480)) {
        var_s1 = &D_801202A0 + 0x60;
        do {
            if ((func_8014C308(arg0, (u32) var_s0, 0xB, 2) != 0) && (func_8014C278(arg0, (u32) var_s0, 0x50) != 0)) {
                func_80015978(var_s0 + 4, &sp10);
                sp16 = 0;
                func_8014C3A4(arg0, (u32) var_s0, 0xB, &sp10);
                *var_s1 = (u16) ((s16) *var_s1 / 2);
            }
            var_s0 += 0x10C;
            var_s1 += 0x10C;
        } while ((u32) var_s0 < (u32) &D_80126720);
    }
}
