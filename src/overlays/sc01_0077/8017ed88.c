/* sc01_0077: func_8017ED88 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef signed char s8;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern int func_8005C49C(void);
extern int func_8005C49C(void);
extern s32 func_8005C49C(void);
s32 func_8005C49C();

void func_8017ED88(void *arg0) {
    (*(s32 *)((s8 *)(arg0) + (0x14))) = (s32) (func_8005C49C() + 0xC000);
    (*(s32 *)((s8 *)(arg0) + (0x10))) = (s32) (((func_8005C49C() & 0x3FFF) * 2) - 0x4000);
    (*(s32 *)((s8 *)(arg0) + (0x18))) = (s32) (((func_8005C49C() & 0x3FFF) * 2) - 0x4000);
}
