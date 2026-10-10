/* sc01_0077: func_80178CBC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801789AC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
typedef s32 M2C_UNK;
extern short D_801DAB2C;
extern s32 D_801DA308;
M2C_UNK func_80178D40(s32, s32);
extern s32 D_801DA308;
extern short D_801DAB2C;

void func_80178CBC(s32 arg0, s32 arg1) {
    D_801DA308 = arg1;
    do {
        func_80178D40(arg0, D_801DA308);
    } while (D_801DAB2C == 3);
}
