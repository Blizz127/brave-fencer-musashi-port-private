/* sc03_0001: func_8015D414 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_80154A74(int, int);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_80154A74(s32 a0, s32 a1);
extern unsigned char D_8018EEBC[];
extern void func_801553C0(s32 a0);
extern void func_80154A74(s32 a0, s32 a1);

void func_8015D414(int param_1)
{
    *(unsigned char *)(param_1 + 0x1bd) = 8;
    *(unsigned char **)(param_1 + 0x38) = D_8018EEBC;
    *(short *)(param_1 + 0x138) = 0;
    *(short *)(param_1 + 0x13a) = 0;
    *(short *)(param_1 + 0x13c) = 0;
    *(short *)(param_1 + 0x13e) = 0;
    *(short *)(param_1 + 0xA) = *(short *)(param_1 + 0xA) + 0x48;
    *(short *)(*(int *)(param_1 + 0x20) + 0x10) = 0;
    ((void (*)(void))func_801553C0)();
    func_80154A74(param_1, 0x11);
}
