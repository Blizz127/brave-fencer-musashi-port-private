/* sc01_0077: func_80171D1C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80146D90(s32 a0);
void func_80146D90(s32 a0);
extern void func_80146D90(int);
extern void func_8012A568(void (*a0)(void));
extern void func_80146D90(s32);
extern void func_80146D90(s32 a0);
extern int func_8017250C(short *a0, short *a1);
extern void func_80146D90(s32 a0);
extern s32 func_80171FFC(short *a0, short *a1, s32 a2);
extern int func_8017250C(short *a0, short *a1);
extern void func_80146D90(s32 a0);
s32 func_80171FFC(short *a0, short *a1, s32 a2);
int func_8017250C(short *a0, short *a1);

s32 func_80171D1C(void * a0, void * a1, s32 a2)
{
    s32 ret;
    ret = func_80171FFC(a0, a1, a2 & 0xFF);
    if (func_8017250C(a0, a1) != 0) {
        func_80146D90((s32)a0);
    }
    return ret;
}
