/* sc02_0037: func_8012E8A8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;

void func_8012E8A8(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 0x20);
    p[1] = p[1] | 0x80000000;
}
