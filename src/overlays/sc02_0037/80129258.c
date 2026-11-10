/* sc02_0037: func_80129258 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s16 D_8011DB30;
extern s16 D_8011DB30;
extern s16 D_8011DB30;

void func_80129258(void) {
    s16 *p = &D_8011DB30;
    s32 i = 0x7F;
    do {
        *p = 0;
        p = (s16 *)((s32)p + 0x38);
        i--;
    } while (i >= 0);
}
