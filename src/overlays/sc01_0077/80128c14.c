/* sc01_0077: func_80128C14 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_a.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s16 D_800B9A08;
extern short D_800B9A08;
extern void func_80010AE0(s32 a0);
extern s16 D_800B9A08;

void func_80128C14(void) {
    s32 a0;
    switch (D_800B9A08) {
    case 0x3023:
        a0 = 0x4E0;
        break;
    case 0x3081:
        a0 = 0x420;
        break;
    case 0x3067:
        a0 = 0x480;
        break;
    case 0x3093:
        a0 = 0xFFB;
        break;
    case 0x30A5:
        a0 = 0xFFB;
        break;
    default:
        a0 = 0x3E0;
        break;
    }
    func_80010AE0(a0);
}
