/* sc01_0077: func_8014168C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern u8 D_80115148[];
extern u8 D_80115158[];
extern u8 D_80115148[];
extern u8 D_80115158[];
extern u8 D_80115148[];
extern u8 D_80115149[];
extern u8 D_80115158[];

s16 func_8014168C(s16 a0) {
    s32 i = a0 * 2;
    return D_80115148[i] + D_80115149[i] * D_80115158[i];
}
