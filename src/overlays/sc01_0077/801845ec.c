/* sc01_0077: func_801845EC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012A828(int a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8012BCCC(s32 a0);
extern void func_8018469C(s32 param_1);
extern void func_8012A828(s32 a0, void *a1);
extern u8 D_8019731C;
void func_8018469C(s32 param_1);

s32 func_801845EC(s32 param_1, s32 param_2, s32 param_3) {
    s32 iVar2;
    s16 sVar1;
    iVar2 = func_8012BCCC(param_1);
    if (param_2 >= iVar2) {
        func_8018469C(param_1);
        return 1;
    }
    sVar1 = *(s16 *)(param_1 + 0xdc) + 1;
    *(s16 *)(param_1 + 0xdc) = sVar1;
    if (sVar1 < 0x79) {
        return 0;
    }
    if (param_3 >= iVar2) {
        return 0;
    }
    *(s16 *)(param_1 + 2) = 1;
    func_8012A828(param_1, &D_8019731C);
    return 1;
}
