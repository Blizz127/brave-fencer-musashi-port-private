/* Overlay range [80158E24,80158F00) from MAIN.CD member 0012.
 * SHA256(span)=fd56b88d4db935edbb47cb680fbeb93345a617e8761de8c992116ee0ee5dc11f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002D4C8(s32, s32);            /* extern */
void func_80146CA0(void *);                      /* static */
s32 func_801487F4();                                /* static */
void func_80154274(void *, void *);           /* static */
void func_80154A74(void *, s32);             /* static */
void func_80159434(void *, s32);             /* static */
extern s32 *D_800D5904;

void func_80158E24(void *arg0) {
    s32 var_s0;
    void *temp_v1;

    var_s0 = 1;
    if (func_801487F4() & 0xF0) {
        var_s0 = 4;
    }
    if (var_s0 > 0) {
        do {
            func_80159434(arg0, 0x4C000);
            temp_v1 = M2C_FIELD(arg0, void **, 0x20);
            var_s0 -= 1;
            if (M2C_FIELD(temp_v1, s16 *, 0x10) < 0xC00) {
                M2C_FIELD(temp_v1, s16 *, 0x10) = 0xC00;
                func_80154274(arg0, &D_800D5904);
                func_80154A74(arg0, 0x20);
                func_8002D4C8(0x2A, 0);
                func_8002D4C8(0x1C, 0);
                func_80146CA0(arg0);
                var_s0 = -1;
            }
        } while (var_s0 > 0);
    }
}
