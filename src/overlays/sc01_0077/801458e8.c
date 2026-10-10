/* sc01_0077: func_801458E8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern s32 D_800AE6AC;
extern s32 D_800AE6B0;
extern s16 D_800B9A0A;
extern u8 D_80078E50;
extern void func_800D185C(u8 *a0);

void func_801458E8(void) {
    D_800AE6B0 = D_800AE6AC | 0x1000000;
    func_800D185C(&D_80078E50);
    D_800B9A0A = 0x3000;
}
