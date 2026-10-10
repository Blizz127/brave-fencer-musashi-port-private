/* sc01_0077: func_80175414 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern u8 D_8011F7A8;
extern u8 D_8011F7A9;
extern u8 D_8011F7AE;
extern u8 D_8011F7A8;
extern u8 D_8011F7A9;
extern u8 D_8011F7AD;
extern u8 D_8011F7AE;

void func_80175414(s32 _arg0)
{
    unsigned char *p = &D_8011F7A8;
    if (*p == 1) {
        *p = 0;
        D_8011F7AD = 10;
        D_8011F7A9 = 0;
        D_8011F7AE = 0x37;
    }
    return;
}
