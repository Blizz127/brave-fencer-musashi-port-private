/* sc01_0077: func_80182988 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80182268.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern s32 D_801B0D50;
extern void func_8012A828(int, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int a0, void *a1);
extern void func_8012A828(int, void *);
extern s32 D_801B0D50;

void func_80182988(int param_1)
{
    *(short *)(param_1 + 2) = 0xb;
    *(short *)(param_1 + 0x34) = 1;
    *(short *)(param_1 + 0x5e) = 0;
    *(unsigned short *)(param_1 + 0x5c) = 0xaa10;
    func_8012A828(param_1, ((unsigned char *)&D_801B0D50));
    *(char *)(param_1 + 0x102) = 0;
    *(int *)(param_1 + 0x1c) = 0x1e;
}
