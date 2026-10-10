/* sc01_0077: func_801858AC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern u8 *func_8012913C(s32 a0);
extern int func_8005C49C(void);
extern u8 *func_8012913C(s32 a0);
extern unsigned short D_801B1568[];

void func_801858AC(s32 param_1, s32 param_2)
{
    int s3;
    unsigned short s0;
    int s2;
    int s1;
    int v0;
    int iVar3;
    s0 = D_801B1568[*(short *)(param_1 + 0xfc)];
    s3 = param_2;
    if (((short *)D_801B1568)[*(short *)(param_1 + 0xfc)] == 0) {
        *(short *)(param_1 + 0xfc) = 0;
        s0 = D_801B1568[0];
    }
    *(short *)(param_1 + 0xfc) = *(short *)(param_1 + 0xfc) + 1;
    v0 = (func_8005C49C() & 3) * 0x400 + 0x1800;
    s2 = v0;
    __asm__ __volatile__("" : "=r"(v0) : "0"(v0));
    s1 = (v0 - 0x1000) * 0x20;
    iVar3 = ((int (*)(int))func_8012913C)(4);
    if (iVar3 != 0) {
        *(short *)(iVar3 + 6) = s3;
        *(short *)(iVar3 + 0xa) = s0;
        *(short *)(iVar3 + 0xe) = 0;
        *(int *)(iVar3 + 0x10) = s1;
        *(short *)(iVar3 + 0x2c) = s2;
    }
}
