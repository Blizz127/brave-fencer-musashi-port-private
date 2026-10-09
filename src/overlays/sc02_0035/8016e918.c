/* SC02.CD member35: func_8016E918 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 D_80115218;

void func_8016E918(short param_1, short param_2) {
    char *p;
    if (param_2 < 10) {
        p = (char *)&D_80115218 + ((s32)param_1 << 5);
        p[0] = param_1 + 1;
        p[3] = param_2;
        p[1] = 0;
    }
}
