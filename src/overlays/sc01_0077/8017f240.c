/* sc01_0077: func_8017F240 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8012A568(void (*a0)(void));
extern s32 D_801270D0;
extern u8 D_8018A868;
extern s32 func_8012C51C(void *a0, s32 a1);

M2C_UNK func_8017F240(void)
{
    s32 *p;
    p = &D_801270D0;
    if (*p == 0) {
        ((void (*)(u8 *, s32))func_8012C51C)(&D_8018A868, 0);
        *p = 1;
    }
}
