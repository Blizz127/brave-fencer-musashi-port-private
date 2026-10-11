/* sc03_0001: func_80171AB0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern s32 func_8014C568(s16 *a0, s16 *a1);
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8014C568(s16 *a0, s16 *a1);
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);

s16 func_80171AB0(s32 param_1, void * _arg1)
{
    short sVar1;
    sVar1 = ((short (*)(void))func_8014C568)();
    sVar1 = ((short (*)(int, int, int))func_80012B04)((int)*(short *)(*(int *)(param_1 + 0x20) + 0x12), (int)sVar1, 4);
    *(unsigned short *)(*(int *)(param_1 + 0x20) + 0x12) =
        *(short *)(*(int *)(param_1 + 0x20) + 0x12) + sVar1 & 0xfff;
    return (int)sVar1;
}
