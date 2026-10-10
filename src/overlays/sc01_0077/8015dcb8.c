/* sc01_0077: func_8015DCB8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_80149374(s32 a0, s32 a1);
extern void func_80149374(s32 arg0, s32 arg1);
extern void func_80149374(int, int);
extern void func_80149374(s32, s32);
extern s8 D_80189438[];
extern void func_80149374(s32 a0, s32 a1);

void func_8015DCB8(s32 param_1) {
    s32 iVar1;
    s32 iVar2;
    iVar2 = *(s32 *)(param_1 + 0x178);
    iVar1 = *(s32 *)(param_1 + 0x234);
    *(s32 *)(param_1 + 0x234) = iVar1 + 1;
    *(s16 *)(iVar2 + 6) = (s16)D_80189438[iVar1] + *(s16 *)(*(s32 *)(iVar2 + 0x78) + 0xc);
    iVar1 = *(s32 *)(param_1 + 0x234);
    *(s32 *)(param_1 + 0x234) = iVar1 + 1;
    *(s16 *)(iVar2 + 10) = (s16)D_80189438[iVar1] + *(s16 *)(*(s32 *)(iVar2 + 0x78) + 0xe);
    iVar1 = *(s32 *)(param_1 + 0x234);
    *(s32 *)(param_1 + 0x234) = iVar1 + 1;
    *(s16 *)(iVar2 + 0xe) = (s16)D_80189438[iVar1] + *(s16 *)(*(s32 *)(iVar2 + 0x78) + 0x10);
    func_80149374(param_1, iVar2 + 4);
}
