/* Overlay range [80154ED8,80154F9C) from MAIN.CD member 0012.
 * SHA256(span)=4bc3ebb62861f3b53d9e7a98a90b78d7194bb4a1e044ced2126e634e8b27ccb4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801550FC(void *, void *);           /* static */
extern s16 D_80078E96;
extern s16 D_80078E9E;
extern s16 D_80078EA6;
extern s32 *D_800D8D10;

void func_80154ED8(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_a0;

    var_a0 = arg1;
    M2C_FIELD(arg0, s32 *, 0xC8) = var_a0;
    if (D_80078E96 & 0x8000) {
        temp_v0 = var_a0 | 0x01000000;
        var_a0 = (s32) &D_800D8D10;
        M2C_FIELD(arg0, s32 *, 0xC8) = temp_v0;
    } else if (((D_80078E9E < 0x10) || (D_80078EA6 < 0x10)) && !(M2C_FIELD(arg0, s32 *, 0x44) & 0xC0)) {
        M2C_FIELD(arg0, s32 *, 0xC8) = (s32) (var_a0 | 0x01000000);
        var_a0 = 0x40000002;
    } else {
        M2C_FIELD(arg0, s32 *, 0xC8) = (s32) (M2C_FIELD(arg0, s32 *, 0xC8) & 0xC0FFFFFF);
    }
    func_801550FC((void *) var_a0, arg0);
}
