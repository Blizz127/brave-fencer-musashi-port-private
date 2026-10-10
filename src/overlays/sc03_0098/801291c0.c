/* sc03_0098: func_801291C0 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s16 D_8011DB30;
extern void func_80016714(void *a0, s32 a1);
extern s16 D_8011DB30;

u8 *func_801291C0(void) {
    u8 *p = (u8 *)&D_8011DB30;
    s32 i = 0;
loop:
    if (*(u16 *)p == 0) {
        func_80016714(p, 0x38);
        return p;
    }
    if (++i < 0x80) {
        p += 0x38;
        goto loop;
    }
    return 0;
}
