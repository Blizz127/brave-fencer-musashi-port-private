/* Native retail instruction export [8005F0C8,8005F228).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8005F290;
extern s32 D_8005F228;
extern s32 D_8005F394;
extern s32 D_8005F450;
extern s32 D_8005F6CC;
extern s32 D_8005F704;
extern s32 D_8007295C;
extern s32 D_80072960;
extern s32 D_80072964;
extern s32 D_80072968;
extern s32 D_8007296C;
extern s32 D_80072970;
extern s32 D_80072980;
extern s32 D_80072990;
extern s32 D_80072994;
extern s32 D_800729A8;
void func_8005C2C8(void *, s32);          /* static */
void func_8005D6A0(void *, s8 *, void *, void *); /* static */
extern s32 func_8005F384;
void func_8005F728();                            /* static */
extern s32 *D_800789B8;
extern s32 *D_80078A00;
extern s32 *D_80078A48;

void func_8005F0C8(s32 arg0, s32 arg1) {
    void *var_a2;
    void *var_a3;
    void *var_s0;
    s32 var_t0;
    s32 var_v1;
    s8 *var_a1;
    void *var_a0;

    D_80072994 = 0;
    D_800729A8 = 0;
    func_8005F728();
    var_s0 = &D_80078A48;
    D_8007295C = &D_8005F290;
    D_80072960 = &D_8005F228;
    D_80072964 = &D_8005F394;
    D_80072968 = &D_8005F450;
    D_8007296C = &D_8005F6CC;
    D_80072970 = &D_8005F704;
    D_80072990 = &D_80078A48;
    D_80072980 = func_8005F384;
    func_8005C2C8(&D_80078A48, 0x1E0);
    var_t0 = 0;
    var_a0 = &D_80078A48 + 0x40;
    var_a3 = &D_80078A00;
    var_a2 = &D_800789B8;
    M2C_FIELD(&D_80078A48, s32 *, 0x30) = arg0;
    M2C_FIELD(&D_80078A48, s32 *, 0x120) = arg1;
    do {
        var_a1 = var_s0 + 0x5D;
        M2C_FIELD(var_a0, s32 *, -0x34) = 0;
        M2C_FIELD(var_a0, void **, -0x30) = var_s0;
        M2C_FIELD(M2C_FIELD(var_a0, void **, -0x10), s8 *, 0) = 0xFF;
        var_v1 = 5;
        M2C_FIELD(M2C_FIELD(var_a0, void **, -0x10), s8 *, 1) = 0;
        M2C_FIELD(var_a0, void **, -4) = var_a2;
        M2C_FIELD(var_a0, void **, 0) = var_a3;
loop_2:
        *var_a1 = 0xFF;
        var_v1 -= 1;
        var_a1 += 1;
        if (var_v1 >= 0) {
            goto loop_2;
        }
        var_a3 += 0x23;
        var_a2 += 0x23;
        var_t0 += 1;
        var_a0 += 0xF0;
        var_s0 += 0xF0;
    } while (var_t0 < 2);
    func_8005D6A0(var_a0, var_a1, var_a2, var_a3);
    D_80072994 = 1;
}
