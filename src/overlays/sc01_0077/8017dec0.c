/* sc01_0077: func_8017DEC0 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8016F398(void);
M2C_UNK func_8017D900(void);
extern void func_8016F398(void);
M2C_UNK func_8017D900();

void func_8017DEC0(void *arg0) {
    func_8016F398();
    (*(u8 *)((s8 *)(arg0) + (0x214))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x214))) + 1);
    func_8017D900();
}
