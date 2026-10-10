/* sc01_0077: func_80184CCC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8012CAE4(void *a0);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern int D_8018AFA8[];

void func_80184CCC(int param_1)
{
    int iVar2;
    short uVar1;
    iVar2 = ((int (*)(void))func_8012C1B8)();
    *(int *)(param_1 + 0x20) = iVar2;
    if (iVar2 == 0) {
        ((void (*)(int))func_8012CAE4)(param_1);
    } else {
        func_8001C214(iVar2, D_8018AFA8[*(short *)(param_1 + 0x70)]);
        uVar1 = *(short *)(*(int *)(param_1 + 100) + 0x36);
        *(short *)(param_1 + 2) = 1;
        *(short *)(param_1 + 0xfe) = 0x7fff;
        *(short *)(param_1 + 0xfc) = uVar1;
    }
    return;
}
