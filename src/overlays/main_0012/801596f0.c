/* Overlay range [801596F0,80159874) from MAIN.CD member 0012.
 * SHA256(span)=cffa3dd3e9345167ff3254676515a268ff81ab38608d9ec2762629d0c112dad6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002850C(s32, s32, s32);   /* extern */
void func_80028620(s32, s32 (*)());      /* extern */
extern s32 D_8018078C;
void func_80129248();                     /* static */
void func_8013C938();                            /* static */
void func_8013C98C();                            /* static */
void func_8013CB20();                            /* static */
void func_80174B6C();                            /* static */
extern s32 *D_800AF630;
extern s32 *D_800AFAE8;
extern s16 D_800B9AAC;
extern s16 D_800B9B00;
extern s16 D_801270C0;

s32 func_801596F0(void *arg0) {
    s32 *var_a0;
    s32 *var_v1;
    s32 temp_v0;
    s32 var_v0;
    void *temp_a0;
    void *temp_a2;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x28) - 1;
    M2C_FIELD(arg0, s32 *, 0x28) = temp_v0;
    if (temp_v0 == -1) {
        func_80174B6C();
        D_800B9AAC = 0x7FFF;
        D_800B9B00 = 0x7FFF;
        temp_a0 = &D_800AF630 + 0x9DA8;
        var_v1 = &D_800AF630 + 0x65AC;
        if ((u32) (&D_800AF630 + 0x65A8) < (u32) temp_a0) {
            do {
                *var_v1 |= 0x80000000;
                var_v1 += 0x38;
            } while ((u32) var_v1 < (u32) (temp_a0 + 4));
        }
        if ((u32) (&D_800AF630 + 0x2A8) < (u32) (&D_800AF630 + 0x65A8)) {
            var_a0 = &D_800AF630 + 0x2AC;
            temp_a2 = &D_800AFAE8 + 4;
            var_v0 = (u32) var_a0 < (u32) temp_a2;
            do {
                if ((var_v0 != 0) || ((u32) var_a0 >= (u32) (&D_800AFAE8 + 0x88))) {
                    *var_a0 |= 0x80000000;
                }
                var_a0 += 0x84;
                var_v0 = (u32) var_a0 < (u32) temp_a2;
            } while ((u32) var_a0 < (u32) (&D_800AF630 + 0x65AC));
        }
        D_801270C0 = 3;
        func_80129248(0);
        func_8013C938();
        func_8013CB20();
        func_8013C98C();
        func_8002850C(0x800, 0x800, 0x800);
        func_80028620(0, D_8018078C);
        func_80028620(1, D_8018078C + 0x10);
        func_80028620(2, D_8018078C + 0x20);
        M2C_FIELD(arg0, s32 *, 0x28) = 0xFF;
        M2C_FIELD(arg0, u8 *, 0x15) = (u8) (M2C_FIELD(arg0, u8 *, 0x15) + 1);
    }
    return 0;
}
