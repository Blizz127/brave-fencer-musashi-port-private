/* sc01_0077: func_801425CC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 (*D_80187F50[])();

s32 func_801425CC(s16 *a0) {
    return D_80187F50[(u16)a0[1]]();
}
