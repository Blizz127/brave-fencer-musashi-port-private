/* sc01_0077: func_8017DD9C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_8016EDEC(s32 _arg0, s32 _arg1, s32 _arg2);
extern void func_8012A568(void (*a0)(void));
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_8017E0EC(void *arg0);
void func_8017E0EC(void *arg0);

s32 func_8017DD9C(s32 param_1) {
    ((void (*)(void *, s32))func_8016EDEC)((void *)func_8017E0EC, 0x1000000);
    *(u8 *)(param_1 + 0x15) = *(u8 *)(param_1 + 0x15) + 1;
    *(s32 *)(param_1 + 0x28) = 10;
    return 0;
}
