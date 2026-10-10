/* sc01_0077: func_80183F4C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012B23C(int);
extern void func_8012B23C(s32 a0);
extern void func_8012B23C(int a0);
extern void func_8012B23C(s32 a0);

void func_80183F4C(int param_1) {
    *(short *)(param_1 + 0x2) = 2;
    *(short *)(param_1 + 0x34) = 0;
    ((void (*)(void))func_8012B23C)();
    *(short *)(param_1 + 0x5c) = 0x800;
    *(short *)(param_1 + 0x84) = 0;
    if (*(short *)(param_1 + 0xfc) < *(short *)(param_1 + 0xe)) {
        *(short *)(param_1 + 0x34) = 0;
    } else {
        *(short *)(param_1 + 0x34) = 1;
    }
    *(int *)(param_1 + 0x1c) = 0x100;
    *(int *)(param_1 + 0xdc) = 0;
}
