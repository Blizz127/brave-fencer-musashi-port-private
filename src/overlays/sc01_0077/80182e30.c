/* sc01_0077: func_80182E30 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80182268.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012B23C(int);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B23C(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B23C(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B23C(s32 a0);
extern void func_8012B23C(int a0);
extern void func_8012A828(int a0, void *a1);
extern void func_8012A828(int, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828();
extern int D_801B06E8;
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B23C(s32 a0);

void func_80182E30(short *param_1)
{
    param_1[1] = 0xe;
    *(short *)((char *)param_1 + 0x34) = 0;
    ((void (*)(void *, void *))func_8012A828)(param_1, &D_801B06E8);
    ((void (*)(void *))func_8012B23C)(param_1);
    *(unsigned short *)((char *)param_1 + 0x5c) = 0xaa10;
}
