/* sc01_0077: func_80183CF4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012C218(void *a0);
extern s32 D_801270CC;
extern void func_8012C098(void);
extern void func_80130D48(int);
extern void func_8012C098(void);
extern void func_8012C218(void *a0);
extern s32 D_801270CC;

void func_80183CF4(int param_1) {
    int iVar1;
    iVar1 = *(int *)(param_1 + 0x1c) + 1;
    *(int *)(param_1 + 0x1c) = iVar1;
    if (iVar1 >= 0x3d) {
        func_80130D48(param_1);
        switch ((int)((unsigned int)*(unsigned short *)(param_1 + 0x70) << 0x10) >> 0x18) {
        case 0:
        case 1:
        case 2:
        case 5:
        case 6:
            ((void (*)(int))func_8012C098)(param_1);
            break;
        case 3:
        case 7:
            ((void (*)(int))func_8012C218)(param_1);
            break;
        case 4:
            D_801270CC = D_801270CC + -1;
            ((void (*)(int))func_8012C218)(param_1);
        }
    } else if (0x1e < iVar1) {
        *(unsigned int *)(*(int *)(param_1 + 0x20) + 4) =
            *(unsigned int *)(*(int *)(param_1 + 0x20) + 4) ^ 0x80000000;
    }
    return;
}
