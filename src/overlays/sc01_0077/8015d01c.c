/* sc01_0077: func_8015D01C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_80146CA0(void *a0);
extern s32 func_80012A60(s32 a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);

void func_8015D01C(int param_1)
{
    extern s32 func_801725F4(u8 *a0);
    extern int D_800D550C;
    short new_var2;
    unsigned short new_var;
    extern int D_8018937C;
    short sVar2;
    int iVar4;
    unsigned short uVar1;
    unsigned short uVar5;
    short sVar3;
    ((void (*)(int, void *)) func_80154274)(param_1, &D_800D550C);
    *((short *) ((*((int *) (param_1 + 0x20))) + 0x10)) = 0;
    iVar4 = *((short *) ((*((int *) (param_1 + 0x20))) + 0x12));
    uVar1 = *((unsigned short *) ((*((int *) ((*((int *) (param_1 + 0x180))) + 0x20))) + 0x12));
    uVar5 = (uVar1 + 0x800) & 0xfff;
    new_var = uVar5;
    new_var2 = new_var;
    sVar2 = func_80012A60(iVar4, (short) uVar1);
    sVar3 = func_80012A60(iVar4, new_var2);
    if (sVar2 < sVar3)
    {
        *((short *) ((*((int *) (param_1 + 0x20))) + 0x12)) = uVar1;
    }
    else
    {
        *((unsigned short *) ((*((int *) (param_1 + 0x20))) + 0x12)) = new_var;
    }
    *((int *) (param_1 + 0x38)) = ((int) (&D_8018937C)) | 0x40000000;
    ((void (*)(int)) func_801725F4)(param_1);
    ((void (*)(int)) func_80146CA0)(param_1);
}
