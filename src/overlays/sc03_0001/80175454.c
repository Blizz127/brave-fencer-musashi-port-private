/* sc03_0001: func_80175454 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
extern u8 D_8011F7A8;
extern u8 D_8011F7A9;
extern u8 D_8011F7AE;
extern u8 D_8011F7A8;
extern u8 D_8011F7A9;
extern u8 D_8011F7AD;
extern u8 D_8011F7AE;
extern u8 D_8011F7A8;
extern u8 D_8011F7A9;
extern u8 D_8011F7AD;
extern u8 D_8011F7AE;

void func_80175454(void) {
    u8 *p = &D_8011F7A8;
    if (*p == 0) {
        *p = 1;
        D_8011F7A9 = 0;
        D_8011F7AD = 0xA;
        D_8011F7AE = 0;
    }
}
