/* sc02_0037: func_8017BCF4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef short s16;
extern void func_8012A4BC(void);
void func_8017B0E4(int param_1, int param_2);
extern void func_8017B0E4(int, int);
extern void func_8017B0E4(int, int);
extern void func_8012A4BC(void);

void func_8017BCF4(int param_1)
{
    extern s16 D_801C9644;
    extern s16 D_801C9A70;
    func_8017B0E4(param_1, 6);
    D_801C9644 = D_801C9644 + 1;
    if (0x18 < D_801C9644) {
        func_8012A4BC();
        D_801C9A70 = 0;
    }
    return;
}
