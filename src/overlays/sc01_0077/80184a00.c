/* sc01_0077: func_80184A00 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern u8 D_800D3918[];
extern void func_8012A568(void (*a0)(void));
extern void func_8012C218(void *a0);
extern void func_8012AD80(s32 a0);
extern void func_8012C218(void *a0);
extern s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012AD80(s32 a0);
extern s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012C218(void *a0);
extern s32 D_8018B00C;
extern u8 D_800D3918[];

void func_80184A00(s32 param_1) {
    ((void (*)(void))func_8012AD80)();
    if (func_8012D5E4(param_1, (s32)&D_8018B00C, (s32)&D_800D3918, 10) != 0 ||
        (*(s32 *)(param_1 + 0x1c) = *(s32 *)(param_1 + 0x1c) - 1) == 0) {
        ((void (*)(s32))func_8012C218)(param_1);
    }
}
