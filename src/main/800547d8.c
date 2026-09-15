/* Main-exec range [800547D8,80054AAC) from the SLUS executable.
 * SHA256(span)=bedbde89bd2f5dba2f9e6d33564c0dea09ce285dd624b350280d96ff7416e064.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80052FCC(void *, void *, void *);   /* static */
void func_80053050(void *, s32, void *);         /* static */
extern s32 *D_800AE688;
extern s32 *D_800C6D44;
extern void *D_800C6D48;
extern s32 D_800C7C70;

void func_800547D8(void *arg0, void *arg1) {
    s32 **var_s0;
    s32 *temp_v0_2;
    s32 *temp_v1_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a1;
    s32 var_s1;
    void *temp_a0;
    void *temp_v0;
    void *var_a2;

    var_a2 = arg0;
    var_s1 = 0;
    var_a1 = 0x64;
loop_1:
    (&D_800C6D48)[var_s1] = var_a2;
    temp_a0 = M2C_FIELD(var_a2, void **, 0x48);
    if (temp_a0 == 0) {
        temp_v1 = M2C_FIELD(var_a2, s32 *, 0);
        if ((temp_v1 == D_800C7C70) || (temp_v1 == 0)) {
            M2C_FIELD(var_a2, s32 *, 0x24) = (s32) M2C_FIELD(var_a2, s32 *, 4);
            M2C_FIELD(var_a2, s32 *, 0x28) = (s32) M2C_FIELD(var_a2, s32 *, 8);
            M2C_FIELD(var_a2, s32 *, 0x2C) = (s32) M2C_FIELD(var_a2, s32 *, 0xC);
            M2C_FIELD(var_a2, s32 *, 0x30) = (s32) M2C_FIELD(var_a2, s32 *, 0x10);
            M2C_FIELD(var_a2, s32 *, 0x34) = (s32) M2C_FIELD(var_a2, s32 *, 0x14);
            M2C_FIELD(var_a2, s32 *, 0x38) = (s32) M2C_FIELD(var_a2, s32 *, 0x18);
            M2C_FIELD(var_a2, s32 *, 0x3C) = (s32) M2C_FIELD(var_a2, s32 *, 0x1C);
            M2C_FIELD(var_a2, void **, 0x40) = (void *) M2C_FIELD(var_a2, void **, 0x20);
            M2C_FIELD(arg1, s32 *, 0) = (s32) M2C_FIELD(var_a2, s32 *, 0x24);
            M2C_FIELD(arg1, s32 *, 4) = (s32) M2C_FIELD(var_a2, s32 *, 0x28);
            M2C_FIELD(arg1, s32 *, 8) = (s32) M2C_FIELD(var_a2, s32 *, 0x2C);
            M2C_FIELD(arg1, s32 *, 0xC) = (s32) M2C_FIELD(var_a2, s32 *, 0x30);
            M2C_FIELD(arg1, s32 *, 0x10) = (s32) M2C_FIELD(var_a2, s32 *, 0x34);
            M2C_FIELD(arg1, s32 *, 0x14) = (s32) M2C_FIELD(var_a2, s32 *, 0x38);
            M2C_FIELD(arg1, s32 *, 0x18) = (s32) M2C_FIELD(var_a2, s32 *, 0x3C);
            M2C_FIELD(arg1, void **, 0x1C) = (void *) M2C_FIELD(var_a2, void **, 0x40);
            M2C_FIELD(var_a2, s32 *, 0) = (s32) D_800C7C70;
        } else {
            var_s1 = var_a1 + 1;
            if (var_a1 == 0x64) {
                M2C_FIELD(arg1, s32 *, 0) = (s32) M2C_FIELD(D_800C6D48, s32 *, 0x24);
                M2C_FIELD(arg1, s32 *, 4) = (s32) M2C_FIELD(D_800C6D48, s32 *, 0x28);
                M2C_FIELD(arg1, s32 *, 8) = (s32) M2C_FIELD(D_800C6D48, s32 *, 0x2C);
                M2C_FIELD(arg1, s32 *, 0xC) = (s32) M2C_FIELD(D_800C6D48, s32 *, 0x30);
                var_a2 = M2C_FIELD(D_800C6D48, void **, 0x40);
                M2C_FIELD(arg1, s32 *, 0x10) = (s32) M2C_FIELD(D_800C6D48, s32 *, 0x34);
                M2C_FIELD(arg1, s32 *, 0x14) = (s32) M2C_FIELD(D_800C6D48, s32 *, 0x38);
                M2C_FIELD(arg1, s32 *, 0x18) = (s32) M2C_FIELD(D_800C6D48, s32 *, 0x3C);
                M2C_FIELD(arg1, void **, 0x1C) = var_a2;
                var_s1 = 0;
            } else {
                temp_v0 = (&D_800C6D48)[var_s1];
                M2C_FIELD(arg1, s32 *, 0) = (s32) M2C_FIELD(temp_v0, s32 *, 0x24);
                M2C_FIELD(arg1, s32 *, 4) = (s32) M2C_FIELD(temp_v0, s32 *, 0x28);
                M2C_FIELD(arg1, s32 *, 8) = (s32) M2C_FIELD(temp_v0, s32 *, 0x2C);
                M2C_FIELD(arg1, s32 *, 0xC) = (s32) M2C_FIELD(temp_v0, s32 *, 0x30);
                var_a2 = M2C_FIELD(temp_v0, void **, 0x40);
                M2C_FIELD(arg1, s32 *, 0x10) = (s32) M2C_FIELD(temp_v0, s32 *, 0x34);
                M2C_FIELD(arg1, s32 *, 0x14) = (s32) M2C_FIELD(temp_v0, s32 *, 0x38);
                M2C_FIELD(arg1, s32 *, 0x18) = (s32) M2C_FIELD(temp_v0, s32 *, 0x3C);
                M2C_FIELD(arg1, void **, 0x1C) = var_a2;
            }
        }
    } else {
        temp_v1_2 = M2C_FIELD(var_a2, s32 *, 0);
        if (temp_v1_2 == D_800C7C70) {
            M2C_FIELD(arg1, s32 *, 0) = (s32) M2C_FIELD(var_a2, s32 *, 0x24);
            M2C_FIELD(arg1, s32 *, 4) = (s32) M2C_FIELD(var_a2, s32 *, 0x28);
            M2C_FIELD(arg1, s32 *, 8) = (s32) M2C_FIELD(var_a2, s32 *, 0x2C);
            M2C_FIELD(arg1, s32 *, 0xC) = (s32) M2C_FIELD(var_a2, s32 *, 0x30);
            M2C_FIELD(arg1, s32 *, 0x10) = (s32) M2C_FIELD(var_a2, s32 *, 0x34);
            M2C_FIELD(arg1, s32 *, 0x14) = (s32) M2C_FIELD(var_a2, s32 *, 0x38);
            M2C_FIELD(arg1, s32 *, 0x18) = (s32) M2C_FIELD(var_a2, s32 *, 0x3C);
            M2C_FIELD(arg1, void **, 0x1C) = (void *) M2C_FIELD(var_a2, void **, 0x40);
        } else {
            var_a2 = temp_a0;
            if (temp_v1_2 == 0) {
                var_a1 = var_s1;
            }
            var_s1 += 1;
            goto loop_1;
        }
    }
    if (var_s1 > 0) {
        var_s0 = (var_s1 * 4) + &D_800C6D44;
        do {
            func_80053050(arg1, *var_s0 + 4, var_a2);
            temp_v0_2 = *var_s0;
            var_s1 -= 1;
            M2C_FIELD(temp_v0_2, s32 *, 0x24) = (s32) M2C_FIELD(arg1, s32 *, 0);
            M2C_FIELD(temp_v0_2, s32 *, 0x28) = (s32) M2C_FIELD(arg1, s32 *, 4);
            M2C_FIELD(temp_v0_2, s32 *, 0x2C) = (s32) M2C_FIELD(arg1, s32 *, 8);
            M2C_FIELD(temp_v0_2, s32 *, 0x30) = (s32) M2C_FIELD(arg1, s32 *, 0xC);
            var_a2 = M2C_FIELD(arg1, void **, 0x1C);
            M2C_FIELD(temp_v0_2, s32 *, 0x34) = (s32) M2C_FIELD(arg1, s32 *, 0x10);
            M2C_FIELD(temp_v0_2, s32 *, 0x38) = (s32) M2C_FIELD(arg1, s32 *, 0x14);
            M2C_FIELD(temp_v0_2, s32 *, 0x3C) = (s32) M2C_FIELD(arg1, s32 *, 0x18);
            M2C_FIELD(temp_v0_2, void **, 0x40) = var_a2;
            temp_v1_3 = *var_s0;
            var_s0 -= 4;
            M2C_FIELD(temp_v1_3, s32 *, 0) = D_800C7C70;
        } while (var_s1 > 0);
    }
    func_80052FCC(&D_800AE688, arg1, var_a2);
}
