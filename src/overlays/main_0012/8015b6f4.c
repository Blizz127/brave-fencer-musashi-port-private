/* Overlay range [8015B6F4,8015B7B4) from MAIN.CD member 0012.
 * SHA256(span)=024cbceb7e883f1a73fd48410134cb709695aa10c32bae852440ba1ac552a1fb.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146994(s32, void *, s32, s32); /* static */
void func_80147300();                     /* static */
void func_80147324();                     /* static */
s32 func_80149AA8();                                /* static */
void func_80154150(void *, s32);             /* static */
void func_80154A74(void *, s32);             /* static */
void func_80156648(void *);                      /* static */
extern s32 *D_800D4A9C;

s32 func_8015B6F4(void *arg0) {
    s32 var_a1;
    s32 var_v0;

    var_v0 = 0;
    if (func_80149AA8() != 0) {
        func_80156648(arg0);
        M2C_FIELD(arg0, s8 *, 0x1AA) = 6;
        M2C_FIELD(arg0, s32 *, 0x23C) = (s32) M2C_FIELD(arg0, s32 *, 0xB4);
        M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 2);
        M2C_FIELD(arg0, u8 *, 0x244) = (u8) M2C_FIELD(arg0, u8 *, 0xBC);
        if (M2C_FIELD(arg0, s32 *, 0xB4) == &D_800D4A9C) {
            var_a1 = 0xB;
        } else {
            var_a1 = 0xC;
        }
        func_80154150(arg0, var_a1);
        func_80154A74(arg0, 0x22);
        M2C_FIELD(arg0, s8 *, 0xDA) = 0;
        func_80146994(4, arg0, 5, 0);
        func_80147324(0x400);
        func_80147300(0x5F3);
        var_v0 = 1;
    }
    return var_v0;
}
