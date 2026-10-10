/* sc01_0077: func_801843C0 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001D0E8(s32 a0, s32 a1, s32 a2);
extern int D_801D100C;
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8001D0E8(s32 a0, s32 a1, s32 a2);
extern int D_801D100C;
extern int D_8018AE70;

void func_801843C0(int param_1)
{
    int v0;
    v0 = ((int (*)(void))func_8012C1B8)();
    *(int *)(param_1 + 0x20) = v0;
    if (v0 == 0) {
        ((void (*)(int))func_8012CAE4)(param_1);
        return;
    }
    ((void (*)(int, int))func_8001C214)(v0, 0);
    func_8001D0E8(*(int *)(param_1 + 0x20), 0x140, 0xf0);
    v0 = ((int (*)(void))func_8012C1B8)();
    *(int *)(param_1 + 0xcc) = v0;
    if (v0 == 0) {
        ((void (*)(int))func_8012CAE4)(param_1);
        return;
    }
    ((void (*)(int, void *))func_8001C214)(v0, &D_801D100C);
    *(int *)(param_1 + 0x58) = (int)&D_8018AE70;
    *(short *)(param_1 + 0x5c) = 0x1800;
    *(short *)(param_1 + 0x2) = 1;
    *(short *)(*(int *)(param_1 + 0x20) + 0x10) = 0;
    *(short *)(*(int *)(param_1 + 0x20) + 0x12) = 0;
    *(short *)(*(int *)(param_1 + 0x20) + 0x14) = 0;
    *(short *)(param_1 + 0xfc) = *(short *)(param_1 + 0xe);
    return;
}
