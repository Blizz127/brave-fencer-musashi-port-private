/* sc03_0001: func_8012927C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern s16 D_8011DB30;
extern s16 D_8011DB30;
extern s16 D_8011DB30;
extern void func_801292C8(u8 *a0);
extern s16 D_8011DB30;
void func_801292C8(u8 *a0);

void func_8012927C(void) {
    s32 i;
    u8 *p = (u8 *)&D_8011DB30;
    for (i = 0; i < 0x80; i++) {
        func_801292C8(p);
        p += 0x38;
    }
}
