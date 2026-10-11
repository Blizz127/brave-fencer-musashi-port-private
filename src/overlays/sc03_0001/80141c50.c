/* sc03_0001: func_80141C50 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80140608.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern u16 D_8011511E;
extern u16 D_8011511E;
extern u16 D_8011511E;
extern s32 func_80015144(void);
extern u16 D_8011511C;
extern u16 D_8011511E;

s32 func_80141C50(void) {
    if (D_8011511C != 0x90F) {
        return 0;
    }
    if ((D_8011511E & 0x800) == 0) {
        return 0;
    }
    return func_80015144() != 0;
}
