/* sc03_0001: func_8017BCA0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
extern s16 D_801EF3F0;
void func_8017B0E4(int param_1, int param_2);
extern s16 D_801EE5DC;
extern s16 D_801EF3F0;
extern s16 D_801EE5DC;
extern s16 D_801EE5DC;
extern void func_8017B0E4(int, int);
extern s16 D_801EE5DC;
extern s16 D_801EF3F0;

void func_8017BCA0(int param_1) {
    func_8017B0E4(param_1, 0xC);
    D_801EE5DC = D_801EE5DC + 1;
    if (D_801EE5DC >= 0x1F) {
        D_801EF3F0 = 2;
    }
}
