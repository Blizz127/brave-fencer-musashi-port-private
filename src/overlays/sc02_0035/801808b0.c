/* SC02.CD member35: func_801808B0 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;

void func_801808B0(s32 param_1)
{
    if (--*(s32 *)(param_1 + 0x1c) == 0) {
        if (*(s32 *)(param_1 + 0x2c) == -1) {
            *(s16 *)(param_1 + 2) = 1;
        } else {
            *(s16 *)(param_1 + 2) = 2;
            *(s32 *)(param_1 + 0x1c) = 0;
        }
    }
}
