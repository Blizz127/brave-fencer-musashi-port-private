/* Main-exec range [80028694,80028A30) from the SLUS executable.
 * SHA256(span)=de0479e6f3926950d785905250305293c9816e5e0631aeba7eef8bb535040ca5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80014B10();                         /* static */
s32 func_80014BFC();                         /* static */
s32 func_80014C54(s32, s32, s32);       /* static */
void func_80058B04(void *, s32, s32, s32, s32); /* static */
extern s32 D_80075818;
extern s32 D_8007581C;
extern s32 *D_80075820;
extern s32 *D_80075824;
extern s32 *D_80075828;
extern s32 *D_8007582C;
extern s32 *D_80075830;
extern s32 *D_80075834;
extern s32 *D_800AF630;
extern s8 D_800AF67F;
extern s8 D_800AF6DB;
extern s8 D_800AF737;
extern s32 *D_800AF77C;
extern s32 *D_800AF780;
extern s32 *D_800AF790;
extern s32 *D_800AF794;
extern s32 *D_800AF7A4;
extern s32 *D_800AF7A8;
extern u8 D_800B9A15;

void func_80028694(void) {
    s32 var_a3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;

    if (D_800B9A15 == 0) {
        if ((func_80014C54(1, 0, 2) << 0x10) != 0) {
            D_800AF737 = 1;
            D_800AF6DB = 1;
            D_800AF67F = 1;
            D_8007581C = 0;
            D_80075818 = 0;
            M2C_FIELD(&D_80075820, u16 *, 0) = (u16) M2C_FIELD(&D_800AF77C, u16 *, 0);
            M2C_FIELD(&D_80075820, u16 *, 2) = (u16) M2C_FIELD(&D_800AF77C, u16 *, 2);
            M2C_FIELD(&D_80075824, u16 *, 0) = (u16) M2C_FIELD(&D_800AF780, u16 *, 0);
            M2C_FIELD(&D_80075824, u16 *, 2) = (u16) M2C_FIELD(&D_800AF780, u16 *, 2);
            M2C_FIELD(&D_80075828, u16 *, 0) = (u16) M2C_FIELD(&D_800AF790, u16 *, 0);
            M2C_FIELD(&D_80075828, u16 *, 2) = (u16) M2C_FIELD(&D_800AF790, u16 *, 2);
            M2C_FIELD(&D_8007582C, u16 *, 0) = (u16) M2C_FIELD(&D_800AF794, u16 *, 0);
            M2C_FIELD(&D_8007582C, u16 *, 2) = (u16) M2C_FIELD(&D_800AF794, u16 *, 2);
            M2C_FIELD(&D_80075830, u16 *, 0) = (u16) M2C_FIELD(&D_800AF7A4, u16 *, 0);
            M2C_FIELD(&D_80075830, u16 *, 2) = (u16) M2C_FIELD(&D_800AF7A4, u16 *, 2);
            M2C_FIELD(&D_80075834, u16 *, 0) = (u16) M2C_FIELD(&D_800AF7A8, u16 *, 0);
            M2C_FIELD(&D_80075834, u16 *, 2) = (u16) M2C_FIELD(&D_800AF7A8, u16 *, 2);
        } else if ((func_80014BFC(1) & 2) && !(func_80014B10(1) & 2)) {
            D_800AF737 = 0;
            D_800AF6DB = 0;
            D_800AF67F = 0;
            M2C_FIELD(&D_800AF77C, u16 *, 0) = (u16) M2C_FIELD(&D_80075820, u16 *, 0);
            M2C_FIELD(&D_800AF77C, u16 *, 2) = (u16) M2C_FIELD(&D_80075820, u16 *, 2);
            M2C_FIELD(&D_800AF780, u16 *, 0) = (u16) M2C_FIELD(&D_80075824, u16 *, 0);
            M2C_FIELD(&D_800AF780, u16 *, 2) = (u16) M2C_FIELD(&D_80075824, u16 *, 2);
            M2C_FIELD(&D_800AF790, u16 *, 0) = (u16) M2C_FIELD(&D_80075828, u16 *, 0);
            M2C_FIELD(&D_800AF790, u16 *, 2) = (u16) M2C_FIELD(&D_80075828, u16 *, 2);
            M2C_FIELD(&D_800AF794, u16 *, 0) = (u16) M2C_FIELD(&D_8007582C, u16 *, 0);
            M2C_FIELD(&D_800AF794, u16 *, 2) = (u16) M2C_FIELD(&D_8007582C, u16 *, 2);
            M2C_FIELD(&D_800AF7A4, u16 *, 0) = (u16) M2C_FIELD(&D_80075830, u16 *, 0);
            M2C_FIELD(&D_800AF7A4, u16 *, 2) = (u16) M2C_FIELD(&D_80075830, u16 *, 2);
            M2C_FIELD(&D_800AF7A8, u16 *, 0) = (u16) M2C_FIELD(&D_80075834, u16 *, 0);
            M2C_FIELD(&D_800AF7A8, u16 *, 2) = (u16) M2C_FIELD(&D_80075834, u16 *, 2);
        }
        if ((func_80014C54(1, 1, 2) << 0x10) != 0) {
            temp_v1 = func_80014B10(1) & 0x5000;
            switch (temp_v1) {                      /* irregular */
            case 0x1000:
                var_v1 = D_8007581C - (M2C_FIELD(&D_800AF630, s32 *, 0xA3E8) * 2);
block_12:
                D_8007581C = var_v1;
                break;
            case 0x4000:
                var_v1 = D_8007581C + (M2C_FIELD(&D_800AF630, s32 *, 0xA3E8) * 2);
                goto block_12;
            }
            temp_v1_2 = func_80014B10(1) & 0xA000;
            if (temp_v1_2 != 0x2000) {
                if (temp_v1_2 == 0x8000) {
                    var_v1_2 = D_80075818 - (M2C_FIELD(&D_800AF630, s32 *, 0xA3E8) * 2);
                    goto block_17;
                }
            } else {
                var_v1_2 = D_80075818 + (M2C_FIELD(&D_800AF630, s32 *, 0xA3E8) * 2);
block_17:
                D_80075818 = var_v1_2;
            }
            var_a3 = 0x140;
            if ((func_80014C54(1, 1, 8) << 0x10) != 0) {
                var_v0 = 0xF0;
            } else {
                var_a3 = 0x280;
                var_v0 = 0x1E0;
            }
            func_80058B04(&D_800AF630 + ((M2C_FIELD(&D_800AF630, u16 *, 0x188) * 0x14) + 0x14C), D_80075818, D_8007581C, var_a3, var_v0);
        }
    }
}
