/* Overlay range [80149954,80149A64) from MAIN.CD member 0012.
 * SHA256(span)=a1cb563357b2d6012e727a94a31885b5b6a60a8b3aa837cf68d555cfb92b037f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015978(void *, void *);        /* extern */
void func_8002D4C8(s32, s32);            /* extern */
void func_800CCF28(void *);                      /* extern */
void func_8012E5CC(void *, s32, s32); /* static */
void func_80146750(s16 *);                       /* static */
void func_80147364(s32, s32);            /* static */
extern s16 D_800B9A08;
extern s32 *D_80126B5C;
extern s32 D_8012707C;

s32 func_80149954(void *arg0) {
    s32 sp28;
    s32 sp24;
    void *sp20;
    s16 sp1E;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    s32 sp10;
    s32 var_v0;

    var_v0 = 0;
    if (!(M2C_FIELD(arg0, s32 *, 0x44) & 0x404)) {
        if (!(M2C_FIELD(arg0, u16 *, 0xAA) & 0x90)) {
            if (D_800B9A08 == 0x308D) {
                func_80015978(&D_80126B5C, &sp10);
                func_8012E5CC(&sp10, 4, 0x8E0);
                return 0;
            }
            func_8002D4C8(4, 0x8E0);
            return 0;
        }
        if (M2C_FIELD(arg0, u16 *, 0xAC) & 0x90) {
            if (D_8012707C == 0x8E0) {
                D_8012707C = 0;
            } else {
                func_80147364(0x8E0, 0);
            }
        }
        func_800CCF28(arg0);
        sp18 = 0x12;
        sp20 = arg0;
        sp1A = 0;
        sp1C = -0x1E;
        sp1E = 0;
        sp24 = 0;
        sp28 = 0;
        func_80146750(&sp18);
        var_v0 = 1;
        /* Duplicate return node #10. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
