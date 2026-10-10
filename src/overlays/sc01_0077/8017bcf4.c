/* sc01_0077: func_8017BCF4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
extern s16 D_801DAAB8;
void func_8017B0E4(int param_1, int param_2);
extern s16 D_801DA71C;
extern s16 D_801DAAB8;
extern s16 D_801DA71C;
extern s16 D_801DA71C;
extern void func_8017B0E4(int, int);
extern s16 D_801DA71C;
extern s16 D_801DAAB8;
extern s16 D_801DA71C;
extern s16 D_801DAAB8;
extern void func_8017B0E4(int, int);
extern void func_8012A4BC(void);

void func_8017BCF4(int param_1)
{
    func_8017B0E4(param_1, 6);
    D_801DA71C = D_801DA71C + 1;
    if (0x18 < D_801DA71C) {
        func_8012A4BC();
        D_801DAAB8 = 0;
    }
    return;
}
