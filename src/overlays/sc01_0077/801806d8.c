/* sc01_0077: func_801806D8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(int, int);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern int func_8012D714(int, int);
extern void func_8002D4C8(s32 a0, s32 a1);
extern unsigned short D_80126B96;
extern void func_8012CC1C(s32 arg0, s32 arg1);
extern int func_8012D714(int, int);
extern void func_8002D4C8(s32 a0, s32 a1);
extern unsigned char D_8018A92C[];
extern int D_8018A924;
extern volatile unsigned short D_80126B96;

void func_801806D8(int param_1) {
    short sVar1;
    int iVar2;
    ((int (*)(int, void *))func_8012CC1C)(param_1, &D_8018A92C);
    if (*(int *)(param_1 + 0x18) < -D_8018A924) {
        *(int *)(param_1 + 0x18) = -D_8018A924;
    }
    if (0x600000 < *(int *)(param_1 + 0x14)) {
        *(int *)(param_1 + 0x14) = 0x600000;
    }
    iVar2 = *(short *)(param_1 + 0x1a) * 0x10;
    *(short *)(*(int *)(param_1 + 0x20) + 0x10) =
        *(short *)(*(int *)(param_1 + 0x20) + 0x10) - iVar2;
    if (func_8012D714(param_1, 1) != 0) {
        D_80126B96 = 2;
        D_80126B96 = D_80126B96 | 0x4000;
    }
    sVar1 = *(short *)(param_1 + 0x84) + 1;
    *(short *)(param_1 + 0x84) = sVar1;
    if (sVar1 < 0x10) {
        return;
    }
    func_8002D4C8(0x48a, 0);
    *(short *)(param_1 + 0x84) = 0;
}
