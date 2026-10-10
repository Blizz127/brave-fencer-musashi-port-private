/* sc01_0077: func_8013E410 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern u8 D_801202A0[];

s32 func_8013E410(void) {
    s32 a0;
    s32 v1;
    v1 = (s32)D_801202A0;
    for (a0 = 0; a0 < 0x60; a0++, v1 += 0x10C) {
        if (*(u16 *)v1 == 0) {
            return v1;
        }
    }
    return 0;
}
