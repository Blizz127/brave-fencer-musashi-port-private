/* sc03_0098: func_80156FA8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 func_80013294(void *a0, void *a1);
extern s32 func_80013294(void *a0, void *a1);

void func_80156FA8(s16 *param_1, s16 *param_2, s16 *param_3)
{
    s16 d[3];
    d[0] = ((s32)param_2[0] - (s32)param_1[0]) / 3;
    d[1] = ((s32)param_2[1] - (s32)param_1[1]) / 3;
    d[2] = ((s32)param_2[2] - (s32)param_1[2]) / 3;
    param_1[3] = 0;
    if (((s32 (*)(s16 *))func_80013294)(param_1) >= 0x41) {
        if (d[0] != 0 || d[1] != 0 || d[2] != 0) {
            param_3[0] = param_2[0] - d[0];
            param_3[1] = param_2[1] - d[1];
            param_3[2] = param_2[2] - d[2];
            param_3[3] = 0;
        } else {
            param_3[3] = 1;
        }
        if (d[0] != 0 || d[1] != 0 || d[2] != 0) {
            param_2[0] = param_1[0] + d[0];
            param_2[1] = param_1[1] + d[1];
            param_2[2] = param_1[2] + d[2];
            param_2[3] = 0;
            return;
        }
        param_2[3] = 1;
        return;
    }
    param_3[3] = 1;
    param_2[3] = 1;
}
