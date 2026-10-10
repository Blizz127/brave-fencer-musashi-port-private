/* sc01_0077: func_801827A4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80182268.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012B23C(int);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B23C(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B23C(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern unsigned char D_801B0908[];
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B23C(s32 a0);
extern void func_80143CD4(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern int func_800CB0E8(int param);

void func_801827A4(int param_1)
{
    *(short *)(param_1 + 2) = 8;
    ((int (*)(int, void *))func_8012A828)(param_1, &D_801B0908);
    ((int (*)(int))func_8012B23C)(param_1);
    *(int *)(param_1 + 0x1c) = 0x78;
    ((int (*)(int))func_80143CD4)(param_1);
    ((int (*)(int, int))func_8002D4C8)(0x47b, 0);
    ((int (*)(int, int))func_8002D4C8)(0x478, 0);
    func_800CB0E8(param_1);
    *(char *)(param_1 + 0xc1) = 6;
}
