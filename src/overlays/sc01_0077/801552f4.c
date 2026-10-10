/* sc01_0077: func_801552F4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 D_800DE2A4[];

void func_801552F4(s32 a0) {
    s32 *p = D_800DE2A4;
    s32 v0 = *p;
    if (v0 != 0) {
        do {
            v0 &= 0x80FFFFFF;
            *p = v0;
            p += 1;
            v0 = *p;
        } while (v0 != 0);
    }
    *(s32 *)(a0 + 0x44) = *(s32 *)(a0 + 0x44) | 0x30000000;
}
