/* sc01_0077: func_80184554 from Druthulu/BFM-decomp
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
extern u8 D_801973C4;

void func_80184554(s32 a0) {
    *(s16 *)(a0 + 0x2) = 2;
    func_8012A828(a0, &D_801973C4);
    *(s32 *)(a0 + 0x1C) = 0x14;
}
