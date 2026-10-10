/* sc01_0077: func_801859AC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012AD50(void *a0);
void func_801858AC(s32 param_1, s32 param_2);
extern void func_801858AC(s32, s32);
extern s32 func_8012AD50(void *a0);

void func_801859AC(int param_1) {
    short uVar1;
    *(short *)(param_1 + 0xfc) = 0;
    *(int *)(param_1 + 0x1c) = 1;
    uVar1 = *(unsigned short *)(param_1 + 0x70) & 7;
    *(short *)(param_1 + 0xfe) = (uVar1 < 2) ? 0x1e : 0xf;
    if (uVar1 != 0) {
        func_801858AC(param_1, -0x80);
        func_801858AC(param_1, -0x30);
        func_801858AC(param_1, 0x20);
        func_801858AC(param_1, 0x70);
        func_801858AC(param_1, 0xc0);
    }
    if (1 < uVar1) {
        func_801858AC(param_1, -0x58);
        func_801858AC(param_1, -0x8);
        func_801858AC(param_1, 0x48);
        func_801858AC(param_1, 0x98);
        func_801858AC(param_1, 0xe8);
    }
    ((void (*)(int))func_8012AD50)(param_1);
}
