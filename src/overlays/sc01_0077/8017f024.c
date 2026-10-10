/* sc01_0077: func_8017F024 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8001CB6C(u8 *a0, s32 a1, s32 a2, s32 a3);
extern void func_8012A568(void (*a0)(void));
extern int func_8005C49C(void);
extern int func_8005C49C(void);
extern s32 func_8005C49C(void);
s32 func_8005C49C();
void func_8017ED88(void *arg0);
extern int func_8005C49C(void);
extern s32 func_8005C49C(void);
extern u8 D_8018A7C0;
extern int func_8005C49C(void);
extern void func_8001CB6C(u8 *a0, s32 a1, s32 a2, s32 a3);
extern void func_8017ED88(void *arg0);
extern u8 D_8018A7C0;

void func_8017F024(int param_1)
{
    s32 p;
    p = *(s32 *)(param_1 + 0x20);
    func_8001CB6C((u8 *)p, (s32)&D_8018A7C0 + (func_8005C49C() & 3) * 0xc, 0x3F0, 0x100);
    *(u8 *)(p + 0x27) = 0x9D;
    *(s16 *)(p + 0x1A) = 0x1000;
    *(s16 *)(p + 0x18) = 0x1000;
    func_8017ED88((void *)param_1);
    *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
}
