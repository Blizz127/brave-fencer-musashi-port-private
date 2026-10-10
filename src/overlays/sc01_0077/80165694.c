/* sc01_0077: func_80165694 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 D_80078EC8;
extern s32 D_80078EC8;
extern s32 D_80078EC8;

void func_80165694(s32 arg0) {
    if (*(s32 *)((s32)arg0 + 0x1F8) & 0x80FFFFFF) {
        return;
    }
    if (D_80078EC8 != 0) {
        D_80078EC8 = D_80078EC8 - 1;
    }
}
