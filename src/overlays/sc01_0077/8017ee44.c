/* sc01_0077: func_8017EE44 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern int func_8005C49C(void);
extern void func_8017EB2C(int a, int b);
extern s32 func_8012BEE8(s32 a0);
extern int func_8005C49C(void);
void func_8017EB2C(int param_1, int param_2);
extern s32 func_8005C49C(void);
s32 func_8005C49C();
extern int func_8005C49C(void);
extern void func_8017EB2C(int a, int b);
extern s32 func_8012BEE8(s32 a0);

void func_8017EE44(int param_1)
{
    int r;
    if ((*(unsigned int *)(param_1 + 0x1c) & 0xf) == 0) {
        r = func_8005C49C();
        func_8017EB2C(r, *(unsigned int *)(param_1 + 0x1c) & 1);
    }
    if (func_8012BEE8(param_1) != 0) {
        *(int *)(param_1 + 0x1c) = 0x30;
        r = func_8005C49C();
        func_8017EB2C(r, func_8005C49C());
    }
}
