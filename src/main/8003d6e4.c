/* Main-exec range [8003D6E4,8003D94C) from the SLUS executable.
 * SHA256(span)=ca248339dd0be6ebfedc4861e03dc4096d9fe25296082fb8799167b97a535829.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B8F4;
extern s32 D_8006B8E4;
extern s32 D_8006B8E8;
extern s32 D_8006B8EC;
extern s32 D_8006B8F0;
extern s32 D_8006B8F5;
extern s32 D_8006B8F6;
extern s32 func_8003D98C;
extern s32 func_8003D9CC;
s32 func_800425B0(u8, s32 (*)());               /* static */
void func_80042610(s32 (*)());               /* static */
void func_8005CF08(s32, s32 (*)());          /* static */
void func_8005CF18();                            /* static */
void func_8005CF68(s32, s32, s32);       /* static */
void func_8005D0A0();                     /* static */

void func_8003D6E4(s32 arg0) {
    s32 (*var_a1)();
    s32 (*var_a1_2)();
    s32 var_s1;
    s32 var_a0;
    s32 var_s0;
    s32 var_v0;
    u8 temp_a0;

    var_a0 = arg0;
    var_v0 = 0x3E6;
    do {
        var_v0 -= 1;
    } while (var_v0 >= 0);
    var_s1 = 0xF2000002;
    var_a1 = D_8006B8F4;
    D_8006B8F4 = 0U;
    D_8006B8F6 = 6U;
    D_8006B8F5 = 0U;
    D_8006B8F0 = 0;
    var_s0 = 0x44E8;
    switch (D_8006B8E4) {                           /* irregular */
    case 0:
        D_8006B8F6 = 0x7FU;
        return;
    case 5:
        D_8006B8F6 = 0U;
        if (var_a0 == 0) {
            D_8006B8F4 = 1U;
        } else {
            var_s1 = 0xF2000003;
            var_s0 = 1;
        }
    case 2:
block_18:
        if (D_8006B8F4 != 0) {
            func_8005CF08(var_a0, var_a1);
            func_80042610(D_8006B8EC);
        } else {
            func_8005CF08(var_a0, var_a1);
            func_8005D0A0(var_s1);
            func_8005CF68(var_s1, var_s0 & 0xFFFF, 0x1000);
            temp_a0 = D_8006B8F6;
            if (temp_a0 == 0) {
                var_a1_2 = func_8003D98C;
                D_8006B8F0 = func_800425B0(0U, 0);
            } else {
                var_a1_2 = func_8003D9CC;
                if (D_8006B8F5 == 0) {
                    var_a1_2 = D_8006B8EC;
                }
            }
            func_800425B0(temp_a0, var_a1_2);
        }
        func_8005CF18();
        return;
    case 3:
        var_s0 = 0x89D0;
        goto block_18;
    default:
        var_a1 = D_8006B8E8;
        if (M2C_FIELD(D_8006B8E8, s32 *, 0) == 0) {
            var_a0 = M2C_FIELD(D_8006B8E8, s32 *, -4);
            if (var_a0 < 0x46) {
                M2C_FIELD(D_8006B8E8, u8 *, 0xD) = (u8) (M2C_FIELD(D_8006B8E8, u8 *, 0xD) + 1);
                var_s0 = 0x204CC0 / var_a0;
            } else {
                var_s0 = 0x409980 / var_a0;
            }
            goto block_18;
        }
        break;
    }
}
