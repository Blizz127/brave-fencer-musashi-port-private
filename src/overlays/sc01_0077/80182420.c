/* sc01_0077: func_80182420 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80182268.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012B2CC(int);
extern void func_8012B23C(int);
extern void func_8012B14C(s32 a0, s32 a1);
extern unsigned char D_801B09D0;
extern unsigned char D_8018AAEC;
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B2CC(s32 a0);
extern void func_8012B23C(s32 a0);
extern void func_8012B14C(s32 a0, s32 a1);
extern unsigned char D_801B09D0;
extern unsigned char D_8018AAEC;
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B2CC(s32 a0);
extern void func_8012B23C(s32 a0);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern unsigned char D_801B09D0;
extern unsigned char D_8018AAEC;
extern unsigned char D_8018AB04;

void func_80182420(int param_1)
{
    *(short *)(param_1 + 0x5c) = 0;
    *(short *)(param_1 + 0x76) = 0;
    *(short *)(param_1 + 0x5c) = 0;
    *(short *)(param_1 + 2) = 6;
    func_8012A828(param_1, &D_801B09D0);
    func_8012B2CC(param_1);
    func_8012B23C(param_1);
    ((void (*)(s32, void *))func_8012B14C)(param_1, &D_8018AAEC);
    *(int *)(param_1 + 0x1c) = 0;
    *(unsigned char *)(param_1 + 0xc2) = 0;
    *(unsigned char *)(param_1 + 0xc3) = 0;
    *(short *)(*(int *)(param_1 + 0x20) + 0x10) = 0x300;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) - 0x240000;
    ((void (*)(s32, void *))func_8012B14C)(param_1, &D_8018AB04);
    func_8012B2CC(param_1);
    func_8002D4C8(0x6aa, 0);
    return;
}
