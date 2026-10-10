/* sc03_0098: func_80129010 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s16 D_8011DB2C;
extern s16 D_8011DB30;
extern s32 D_80126AEC;

void func_80129010(void) {
    s32 i;
    s32 s1;
    s32 idx;
    void (*fp)(s32);
    s1 = (s32)&D_8011DB30;
    if (D_8011DB2C == 0) {
        return;
    }
    i = 0;
    do {
        idx = *(u16 *)s1;
        if (idx != 0) {
            fp = (void (*)(s32))(*(s32 *)((idx << 2) + (*(s32 *)&D_80126AEC)));
            fp(s1);
            if (*(s32 *)(s1 + 0x20) != 0) {
                *(s16 *)(*(s32 *)(s1 + 0x20) + 0x8) = *(u16 *)(s1 + 0x6);
                *(s16 *)(*(s32 *)(s1 + 0x20) + 0xA) = *(u16 *)(s1 + 0xA);
                *(s16 *)(*(s32 *)(s1 + 0x20) + 0xC) = *(u16 *)(s1 + 0xE);
            }
        }
        i++;
        s1 += 0x38;
    } while (i < 0x80);
}
