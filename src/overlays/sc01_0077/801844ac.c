/* sc01_0077: func_801844AC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012A828(int a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void D_80196F3C;

void func_801844AC(s32 arg0)
{
    if (((*(u8 *)((s8 *)(arg0) + (0xC3))) & 1) && ((*(void **)((s8 *)(arg0) + (0x90))) != &D_80196F3C)) {
        func_8012A828(arg0, &D_80196F3C);
    }
}
