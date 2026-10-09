/* SC02.CD member35: func_8017BCF4 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef short s16;
extern s16 D_801BE9D0;
void func_8017B0E4(int param_1, int param_2);
extern s16 D_801BE834;
extern s16 D_801BE9D0;
extern s16 D_801BE834;
extern s16 D_801BE834;
extern void func_8017B0E4(int, int);
extern s16 D_801BE834;
extern s16 D_801BE9D0;
extern s16 D_801BE9D0;
extern void func_8017B0E4(int, int);
extern void func_8012A4BC(void);

void func_8017BCF4(int param_1)
{
    func_8017B0E4(param_1, 6);
    D_801BE834 = D_801BE834 + 1;
    if (0x18 < D_801BE834) {
        func_8012A4BC();
        D_801BE9D0 = 0;
    }
    return;
}
