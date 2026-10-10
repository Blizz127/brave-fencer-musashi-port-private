/* sc01_0077: func_8018469C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012A828(int a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_80142414(s32 a0, s16 a1);
extern u8 D_801970DC;

void func_8018469C(s32 param_1) {
    *(s16 *)(param_1 + 2) = 4;
    func_8012A828(param_1, &D_801970DC);
    *(s32 *)(param_1 + 0x1c) = 0x1e;
    if (*(s16 *)(param_1 + 0xfc) == 0) {
        *(s16 *)(param_1 + 0xfc) = 1;
        ((void (*)(s32, s32))func_80142414)(param_1, -0x96);
    }
}
