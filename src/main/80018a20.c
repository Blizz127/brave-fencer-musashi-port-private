/* Exact retail word export for [80018A20,80018C64); EXE and assembly verified. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_80018A20
"
    ".ent	func_80018A20
"
    ".type	func_80018A20, @function
"
    "func_80018A20:
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
    ".end	func_80018A20
"
    ".size	func_80018A20, .-func_80018A20
"
);
#else
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80062BAC;
extern s32 D_80062BB4;
extern s32 D_80062BBD;
extern s32 D_800747B9;
void func_80018F88(void *);                            /* static */
void func_80018FC8();                                  /* static */
s32 func_80028D58();                                /* static */
s32 func_8005D184();                               /* static */
s32 func_8005D244(s32, s32, s32);                         /* static */
void func_8005D4B8(s32, s32 (*)());                        /* static */
void func_8005D538(s32, u8 *, s32);                        /* static */
extern u8 D_80062BBC;
extern u8 D_800747B8;
extern s32 *D_80078D98;
extern s32 D_800A5E78;
extern u32 D_800AE610;

s32 func_80018A20(s32 arg0) {
    s32 var_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    void *temp_s1;

    var_s2 = saved_reg_s2;
    temp_s1 = (arg0 * 0x4C) + &D_80078D98;
    switch (arg0) {                                 /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        var_s2 = 0;
        break;
    case 1:                                         /* switch 1 */
        var_s2 = 0x10;
        break;
    }
    temp_v0_2 = func_8005D184(var_s2);
    temp_v0 = temp_v0_2 < 2;
    if (temp_v0_2 != 1) {
        if (temp_v0 != 0) {
            if (temp_v0_2 != 0) {
                return temp_v0;
            }
            if (arg0 == 0) {
                temp_v0_3 = (u32) D_800AE610 < 0xAU;
                D_800AE610 += 1;
                if (temp_v0_3 == 0) {
                    D_800AE610 = 0;
                    D_800A5E78 = 0;
                }
            }
            goto block_15;
        }
        switch (temp_v0_2) {                        /* switch 2; irregular */
        case 2:                                     /* switch 2 */
            if (arg0 == 0) {
                D_800AE610 = 0;
                if (func_8005D244(var_s2, 2, 0) == 0) {
                    if (func_80028D58() == 0) {
                        if ((temp_s1->unk4A | temp_s1->unk4B) != 0) {
                            D_80062BBD = 1;
                            temp_s1->unk4B = 0U;
                        } else {
                            D_80062BBD = 0;
                            temp_s1->unk4B = 0U;
                        }
                        temp_s1->unk4A = 0U;
                    } else {
                        func_80018FC8();
                    }
                    func_8005D538(var_s2, &D_80062BBC, 2);
                    func_8005D4B8(var_s2, D_80062BAC);
                    return 1;
                }
            }
            return 1;
        case 6:                                     /* switch 2 */
            if (arg0 == 0) {
                D_800AE610 = 0;
                if (func_8005D244(var_s2, 2, 0) != 0) {
                    if (func_80028D58() == 0) {
                        D_800747B8 = temp_s1->unk4A;
                        D_800747B9 = (u8) temp_s1->unk4B;
                        temp_s1->unk4B = 0U;
                        temp_s1->unk4A = 0U;
                    } else {
                        func_80018FC8();
                    }
                    func_8005D538(var_s2, &D_800747B8, 2);
                    func_8005D4B8(var_s2, D_80062BB4);
                }
            }
            /* Duplicate return node #31. Try simplifying control flow for better match */
            return 1;
        default:                                    /* switch 2 */
            return 6;
        }
    } else {
block_15:
        func_80018F88(temp_s1);
        return 0;
    }
}
#endif

