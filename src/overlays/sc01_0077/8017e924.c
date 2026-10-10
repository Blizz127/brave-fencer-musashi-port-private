/* sc01_0077: func_8017E924 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_80171B4C(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80171B4C(s32 a0, s32 a1);
extern s32 func_80171B4C(s32 a0, s32 a1);
extern s32 func_80171B4C(s32 a0, s32 a1);

void func_8017E924(int param_1)
{
    if (func_80171B4C(param_1, 8) != 0) {
        *(int *)(param_1 + 0x204) = 0x20;
        *(unsigned short *)(param_1 + 0xac) = 0xc040;
        *(unsigned short *)(param_1 + 0xaa) = 0xc040;
        *(unsigned char *)(param_1 + 0x214) = *(unsigned char *)(param_1 + 0x214) + 1;
    }
    return;
}
