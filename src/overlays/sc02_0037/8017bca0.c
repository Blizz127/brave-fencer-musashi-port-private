/* sc02_0037: func_8017BCA0 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef short s16;
void func_8017B0E4(int param_1, int param_2);
extern void func_8017B0E4(int, int);

void func_8017BCA0(int param_1) {
    extern s16 D_801C9644;
    extern s16 D_801C9A70;
    func_8017B0E4(param_1, 0xC);
    D_801C9644 = D_801C9644 + 1;
    if (D_801C9644 >= 0x1F) {
        D_801C9A70 = 2;
    }
}
