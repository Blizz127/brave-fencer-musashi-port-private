/* sc01_0077: func_8018047C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8002D4C8(int, int);
extern void func_8002D4C8(s32 a0, s32 a1);
void func_8017F694(void *arg0);
void func_8017F714_impl(int param_1) __asm__("func_8017F714");
void func_8017F714_impl(int param_1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern int func_8012D714(int, int);
extern void func_8017F694(void *arg0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern unsigned short D_80126B96;

void func_8018047C(int param_1)
{
    int iVar1;
    if ((*(char *)(param_1 + 0x70) == 4) || (iVar1 = ((int (*)(void))func_8012BEE8)(), iVar1 != 0)) {
        int sum;
        sum = *(int *)(param_1 + 0xe0);
        sum += *(int *)(param_1 + 0xe4);
        *(int *)(param_1 + 0xdc) += sum;
        *(int *)(param_1 + 0xe0) = sum;
        *(short *)(*(int *)(param_1 + 0x20) + 0x10) = *(unsigned short *)(param_1 + 0xde);
        if (0x3ff < *(short *)(param_1 + 0xde)) {
            if (*(unsigned short *)(param_1 + 0x34) == 0 &&
                (iVar1 = func_8012D714(param_1, 2), iVar1 != 0)) {
                D_80126B96 = 0x4002;
            }
            if (2 <= *(unsigned short *)(param_1 + 0x34)) {
                ((void (*)(int))func_8017F694)(param_1);
            } else {
                register int cnt __asm__("$4");
                if (*(unsigned short *)(param_1 + 0x34) == 0) {
                    func_8002D4C8(0x487, 0);
                }
                cnt = *(unsigned short *)(param_1 + 0x34) + 1;
                *(int *)(param_1 + 0xdc) = 0x4000000;
                *(unsigned short *)(param_1 + 0x5c) = *(unsigned short *)(param_1 + 0x5c) | 0xcc00;
                *(int *)(param_1 + 0xe0) = -(*(int *)(param_1 + 0xe0) >> 1);
                *(unsigned short *)(param_1 + 0x34) = cnt;
            }
        }
    }
}
