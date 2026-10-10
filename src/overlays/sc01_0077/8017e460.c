/* sc01_0077: func_8017E460 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef s32 M2C_UNK;
M2C_UNK func_8017F240();
M2C_UNK func_8017F240(void);

void func_8017E460(void *arg0) {
    s32 temp_v0;
    temp_v0 = (*(s32 *)((s8 *)(arg0) + (0x204))) - 1;
    (*(s32 *)((s8 *)(arg0) + (0x204))) = temp_v0;
    if (temp_v0 == -1) {
        func_8017F240();
        (*(s32 *)((s8 *)(arg0) + (0x204))) = 0x40;
        (*(u8 *)((s8 *)(arg0) + (0x214))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x214))) + 1);
    }
}
