/* Overlay range [8012832C,80128420) from MAIN.CD member 0012.
 * SHA256(span)=22c3ea89192a584021748e27429b706094b404f86db0145d80b33635872b46b1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80011C10();                                  /* extern */
s32 func_80029178();                               /* extern */
s32 func_80029504();                                /* extern */
s32 func_800CF854(s32);                             /* extern */
s32 func_801288B0();                                /* static */
s32 func_801288E8(s32);                             /* static */
s32 func_80128940(s32);                             /* static */
s32 func_80128998();                                /* static */
s32 func_801289F0();                                /* static */
extern s16 D_800B9A08;

void func_8012832C(void) {
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = func_80029504();
    switch (D_800B9A08) {                           /* irregular */
    case 0x300E:
        if (func_800CF854(temp_a0) == 0) {
            var_v0 = func_80128998();
        } else {
            var_v0 = func_801289F0();
        }
block_15:
        if (var_v0 != 0) {
        default:
            func_80011C10();
        }
        break;
    case 0x30A0:
        if (temp_a0 < 0x640) {
            var_v0 = func_801288E8(temp_a0);
        } else {
            var_v0 = func_80128940(temp_a0);
        }
        goto block_15;
    case 0x3014:
        var_v0 = 1;
        if (temp_a0 == 0x4B0) {
            var_v0 = 1;
            if (!(func_80029178(0x138) & 0xFF)) {
                var_v0 = func_801288B0();
            }
        }
        goto block_15;
    }
}
