/* sc01_0077: func_801426D4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_8012AD50(void *a0);
extern s32 func_8012AD50(void *a0);

void func_801426D4(s32 a0) {
    s32 s0 = *(s32 *)(a0 + 0x20);
    s16 fc = *(s16 *)(a0 + 0xFC);
    if (fc != 0) {
        *(s16 *)(a0 + 0xFC) = fc - 0x10;
        *(u16 *)(s0 + 0x18) += 0x800;
        *(u16 *)(s0 + 0x1A) += 0x800;
    } else {
        *(s32 *)(a0 + 0x1C) = 0xC;
        func_8012AD50((void *)a0);
        *(u16 *)(s0 + 0x1A) = 0x1800;
        *(u16 *)(s0 + 0x18) = 0x1800;
    }
}
