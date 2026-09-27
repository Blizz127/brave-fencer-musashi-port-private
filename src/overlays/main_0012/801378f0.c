/* Overlay range [801378F0,801379D8) from MAIN.CD member 0012.
 * SHA256(span)=b701331abb8cc5df830599b68c5fb643e19a49ef37deefd51c7a811f4a8a2e6b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016714(void *, s32);          /* extern */
extern s32 D_8017E936[];
extern s32 D_8017E93A[];
void func_8013A860();                            /* static */
extern s32 *D_801269F0;
extern s32 *D_80126A28;
extern s32 *D_80126A2A;
extern s32 *D_80126A2C;
extern s32 *D_80126A2E;
extern s32 *D_80127520;
extern s32 *D_8017E934;
extern s32 *D_8017E938;

void func_801378F0(void) {
    void *var_s2;
    s32 var_s0;
    s32 var_s1;
    s32 var_s3;
    u16 temp_v0;

    func_80016714(&D_80127520, 0xBFC);
    var_s3 = 0;
    var_s1 = 0;
    var_s2 = &D_801269F0;
    var_s0 = 0;
    do {
        func_80016714(var_s2, 0x4C);
        *(&D_80126A28 + var_s0) = *(&D_8017E934 + var_s1);
        var_s2 += 0x4C;
        *(&D_80126A2A + var_s0) = *(D_8017E936 + var_s1);
        var_s3 += 1;
        *(&D_80126A2C + var_s0) = *(&D_8017E938 + var_s1);
        temp_v0 = *(D_8017E93A + var_s1);
        var_s1 += 8;
        *(&D_80126A2E + var_s0) = temp_v0;
        var_s0 += 0x4C;
    } while (var_s3 < 3);
    func_8013A860();
}
