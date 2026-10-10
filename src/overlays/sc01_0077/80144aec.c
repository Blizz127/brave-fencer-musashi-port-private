/* sc01_0077: func_80144AEC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern int func_80144B14(int param_1);
int func_80144B14(int param_s0);

void func_80144AEC(s32 *a0) {
    s32 old;
    old = *(s32 *)((s32)a0 + 0xDC);
    *(s32 *)((s32)a0 + 0xDC) = (s32)&func_80144B14;
    *(s16 *)((s32)a0 + 0x0) = 0x83;
    *(s16 *)((s32)a0 + 0x2) = 1;
    *(s32 *)((s32)a0 + 0xCC) = old;
}
