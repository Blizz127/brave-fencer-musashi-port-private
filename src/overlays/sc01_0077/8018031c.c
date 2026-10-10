/* sc01_0077: func_8018031C from Druthulu/BFM-decomp
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
extern s32 func_8012CE2C(s32 a0);
extern void func_8012CBCC(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_8018031C(int param_1)
{
    short sVar2;
    if (((int (*)(void))func_8012CE2C)() == 0) {
        func_8012CBCC(param_1);
    }
    sVar2 = *(short *)(param_1 + 0x84) + 1;
    *(short *)(param_1 + 0x84) = sVar2;
    if ((*(short *)(param_1 + 0xdc) != *(short *)(param_1 + 6)) ||
        (*(short *)(param_1 + 0xde) != *(short *)(param_1 + 0xe))) {
        if (0xf < sVar2) {
            func_8002D4C8(0x485, 0);
            *(short *)(param_1 + 0x84) = 0;
        }
        *(short *)(param_1 + 0xdc) = *(short *)(param_1 + 6);
        *(short *)(param_1 + 0xde) = *(short *)(param_1 + 0xe);
    }
    return;
}
