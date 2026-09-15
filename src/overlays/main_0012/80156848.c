/* Overlay range [80156848,80156A14) from MAIN.CD member 0012.
 * SHA256(span)=7c1b548a06b35a6cf4d2fe221e5f2e4eae652530140d6f7800525c692d9d770a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80013E94(void *, s32 *);               /* extern */
void func_801469C8(s32, s32, s16, s16, s32, s32, s32, s32); /* static */
void func_80146A6C(u8, s32, s16, s16, s32, s32, s32); /* static */
void func_80156A1C(s32, u32);                    /* static */
extern s32 *D_801151E0;
extern s32 *D_80126730;
extern s32 *D_80126AF0;
extern s32 *D_80126AF2;
extern s32 *D_80126AF4;
extern s32 *D_80128120;
extern s32 *D_80128138;

void func_80156848(s32 arg0, void *arg1) {
    s32 sp20;
    s32 *temp_s1;
    s32 temp_v1;
    s32 var_s0;
    u32 var_s2;

    var_s2 = 0;
    var_s0 = 0;
    do {
        temp_s1 = (var_s2 * 4) + &D_801151E0;
        temp_v1 = *temp_s1;
        if (temp_v1 & 1) {
            func_80013E94(var_s0 + &D_80128120, &sp20);
            func_80146A6C(M2C_FIELD(arg1, u8 *, 8), arg0, *(&D_80126AF0 + var_s0), *(&D_80126AF2 + var_s0), (s32) *(&D_80126AF4 + var_s0), sp20, (s32) M2C_FIELD(arg1, u8 *, 9));
            var_s2 += 1;
        } else {
            if (temp_v1 & 6) {
                func_80156A1C(arg0, var_s2);
                func_80013E94(var_s0 + &D_80128138, &sp20);
                if ((*temp_s1 & 6) == 4) {
                    sp20 |= 0x80000000;
                }
                func_80146A6C(6U, arg0, *(&D_80126AF0 + var_s0), *(&D_80126AF2 + var_s0), (s32) *(&D_80126AF4 + var_s0), sp20, 0);
                if (*(&D_80126730 + var_s2) == 0x24) {
                    func_801469C8(0x53, arg0, *(&D_80126AF0 + var_s0), *(&D_80126AF2 + var_s0), (s32) *(&D_80126AF4 + var_s0), sp20, 0, 0x14);
                }
            }
            var_s2 += 1;
        }
        var_s0 += 8;
    } while (var_s2 < 3U);
}
