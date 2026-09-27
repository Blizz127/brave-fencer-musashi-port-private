/* Main-exec range [8003DA1C,8003DC90) from the SLUS executable.
 * SHA256(span)=f3b2ecbab050a80cb054aba94763fd6b0f52a88797f577b0b208b4c4bf408214.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003DC90(s16, s32);                    /* static */
void func_8003DF8C(s16, s32);                    /* static */
void func_8003E248(s16, s32);                    /* static */
void func_8003E2E4(s16, s32);                    /* static */
void func_8003EBB0(s16, s32);                    /* static */
void func_8003EC10(s16, s32);                    /* static */
void func_8003EEE4(s16, s32);                    /* static */
void func_8003FA64();                            /* static */
extern s32 D_800A6510;
extern s32 D_800AE818;
extern s32 *D_800C73D8;
extern s16 D_800C7C58;
extern s16 D_800C7C7C;

void func_8003DA1C(void) {
    s16 var_s7;
    s32 *var_fp;
    s32 temp_s1;
    s32 var_s0;
    s32 var_s3;
    s32 var_s6;

    if (D_800A6510 != 1) {
        D_800A6510 = 1;
        var_s7 = 0;
        func_8003FA64();
        if (D_800C7C58 > 0) {
            var_fp = &D_800C73D8;
            do {
                if (D_800AE818 & (1 << var_s7)) {
                    var_s6 = 0;
                    if (D_800C7C7C > 0) {
                        var_s3 = 0;
                        var_s0 = 0;
                        do {
                            if (M2C_FIELD((var_s0 + *var_fp), s32 *, 0x98) & 1) {
                                temp_s1 = var_s3 >> 0x10;
                                func_8003E2E4(var_s7, temp_s1);
                                if (M2C_FIELD((var_s0 + *var_fp), s32 *, 0x98) & 0x10) {
                                    func_8003DC90(var_s7, temp_s1);
                                }
                                if (M2C_FIELD((var_s0 + *var_fp), s32 *, 0x98) & 0x20) {
                                    func_8003DF8C(var_s7, temp_s1);
                                }
                                if (M2C_FIELD((var_s0 + *var_fp), s32 *, 0x98) & 0x40) {
                                    func_8003EEE4(var_s7, temp_s1);
                                }
                                if (M2C_FIELD((var_s0 + *var_fp), s32 *, 0x98) & 0x80) {
                                    func_8003EEE4(var_s7, temp_s1);
                                }
                            }
                            if (M2C_FIELD((var_s0 + *var_fp), s32 *, 0x98) & 2) {
                                func_8003E248(var_s7, var_s3 >> 0x10);
                            }
                            if (M2C_FIELD((var_s0 + *var_fp), s32 *, 0x98) & 8) {
                                func_8003EBB0(var_s7, var_s3 >> 0x10);
                            }
                            if (M2C_FIELD((var_s0 + *var_fp), s32 *, 0x98) & 4) {
                                func_8003EC10(var_s7, var_s3 >> 0x10);
                                M2C_FIELD((var_s0 + *var_fp), s32 *, 0x98) = 0;
                            }
                            var_s3 += 0x10000;
                            var_s6 += 1;
                            var_s0 += 0xB0;
                        } while (var_s6 < D_800C7C7C);
                    }
                }
                var_s7 += 1;
                var_fp += 4;
            } while (var_s7 < D_800C7C58);
        }
        D_800A6510 = 0;
    }
}
