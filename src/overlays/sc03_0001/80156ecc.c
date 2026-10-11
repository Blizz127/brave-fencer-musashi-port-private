/* sc03_0001: func_80156ECC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_80147478(s32 a0);
extern void func_80149350(s32 arg0);
void func_80156FA8(s16 *param_1, s16 *param_2, s16 *param_3);

void func_80156ECC(int param_1, int param_2, int param_3, int param_4, int param_5) {
    extern void func_80156FA8(s16 *param_1, s16 *param_2, s16 *param_3);
    extern void func_80147478(s32 a0);
    extern void func_80149350(s32 arg0);
    unsigned short uVar1;
    func_80156FA8(param_3, param_4, param_5);
    ((s32 (*)(s32))func_80147478)(param_1);
    ((s32 (*)(s32, s32, s32))func_80149350)(param_1, param_2, param_2);
    uVar1 = *(unsigned short *)(param_3 + 6);
    if (*(short *)(param_3 + 6) == 0) {
        ((s32 (*)(s32, s32, s32))func_80149350)(param_1, param_3, param_3);
        *(unsigned short *)(param_3 + 6) = uVar1;
    }
    uVar1 = *(unsigned short *)(param_4 + 6);
    if (*(short *)(param_4 + 6) == 0) {
        ((s32 (*)(s32, s32, s32))func_80149350)(param_1, param_4, param_4);
        *(unsigned short *)(param_4 + 6) = uVar1;
    }
    uVar1 = *(unsigned short *)(param_5 + 6);
    if (*(short *)(param_5 + 6) == 0) {
        ((s32 (*)(s32, s32, s32))func_80149350)(param_1, param_5, param_5);
        *(unsigned short *)(param_5 + 6) = uVar1;
    }
}
