/* Overlay range [80131170,801312D0) from MAIN.CD member 0012.
 * SHA256(span)=e765700fde7de8fa864febcdd07325a9bbde6923b14b63c12f643e0a7dfd2f0a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017E6E4;
void func_8012B14C(void *, s32 (*)());       /* static */
s32 func_8012BCCC(void *);                          /* static */
s32 func_80131A34(void *, s32);                     /* static */
s32 func_80131AC8(void *, s32);                 /* static */
void func_80131B14();                            /* static */

void func_80131170(void *arg0, s32 (*arg1)(), s32 arg2) {
    s32 (*var_s1)();
    s32 var_a1;
    var_s1 = arg1;
    func_80131B14();
    M2C_FIELD(arg0, s8 *, 0xC2) = 0;
    M2C_FIELD(arg0, s8 *, 0xC3) = 0;
    M2C_FIELD(arg0, s16 *, 0x98) = 0;
    if (var_s1 == 0) {
        var_s1 = D_8017E6E4;
    }
    func_8012B14C(arg0, var_s1);
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    if (arg2 != 0) {
        if ((func_80131A34(arg0, arg2) == 0) && (func_80131A34(arg0, 0x24) == 0)) {
            M2C_FIELD(arg0, s32 *, 0xC4) = (s32) (M2C_FIELD(arg0, s32 *, 0xC4) & ~4);
            if (func_80131A34(arg0, 0x20) == 0) {
                M2C_FIELD(arg0, s16 *, 0x98) = 0;
            } else {
                goto block_9;
            }
        }
    } else if (func_80131A34(arg0, 0x24) == 0) {
        M2C_FIELD(arg0, s32 *, 0xC4) = (s32) (M2C_FIELD(arg0, s32 *, 0xC4) & ~4);
        if (func_80131A34(arg0, 0x20) != 0) {
block_9:
            M2C_FIELD(arg0, s32 *, 0xC4) = (s32) (M2C_FIELD(arg0, s32 *, 0xC4) | 4);
        } else {
            M2C_FIELD(arg0, s16 *, 0x98) = 0;
        }
    }
    if (M2C_FIELD(arg0, s16 *, 0x76) <= 0) {
        if (func_8012BCCC(arg0) <= 0x8FFF) {
            if (func_80131AC8(arg0, 0x32) == 0) {
                var_a1 = 0x33;
                goto block_17;
            }
        } else if (func_80131AC8(arg0, 0x33) == 0) {
            var_a1 = 0x32;
block_17:
            func_80131AC8(arg0, var_a1);
        }
    }
}
