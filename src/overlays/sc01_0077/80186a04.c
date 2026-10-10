/* sc01_0077: func_80186A04 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern int func_8012BEE8(int a0);
extern void func_8012AD80(s32 a0);
extern void func_8012C218(void *a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012AD80(s32 a0);
extern void func_8012C218(void *a0);
extern s32 func_8012BEE8(s32);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern void func_8012AD80(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012AD80(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);

void func_80186A04(int param_1)
{
    int iVar1;
    ((void (*)(void))func_8012AD80)();
    if (*(int *)(param_1 + 0x1c) >= 0x30) {
        *(unsigned int *)(*(int *)(param_1 + 0x20) + 4) =
            *(unsigned int *)(*(int *)(param_1 + 0x20) + 4) | 0x80000000;
    } else {
        *(unsigned int *)(*(int *)(param_1 + 0x20) + 4) =
            *(unsigned int *)(*(int *)(param_1 + 0x20) + 4) & 0x7fffffff;
    }
    *(short *)(*(int *)(param_1 + 0x20) + 0x10) =
        *(short *)(*(int *)(param_1 + 0x20) + 0x10) + 0x17;
    *(short *)(*(int *)(param_1 + 0x20) + 0x12) =
        *(short *)(*(int *)(param_1 + 0x20) + 0x12) + 0x43;
    *(short *)(*(int *)(param_1 + 0x20) + 0x14) =
        *(short *)(*(int *)(param_1 + 0x20) + 0x14) + 0x58;
    iVar1 = func_8012BEE8(param_1);
    if (iVar1 != 0) {
        ((void (*)(int))func_8012C218)(param_1);
    }
    return;
}
