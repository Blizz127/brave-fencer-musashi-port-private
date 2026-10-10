/* sc01_0077: func_80184B24 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012BEE8(s32 a0);
extern int func_8012BEE8(int a0);
extern void func_8012C098(void);
extern void func_8012C098(void);
extern void func_8012C098(void);
s32 func_801845EC(s32 param_1, s32 param_2, s32 param_3);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012C044(s32 a0);
extern void func_8012C098(void);
extern s32 func_8012BEE8(s32);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_801845EC(s32 a0, s32 a1, s32 a2);
extern s32 func_8012C044(s32 a0);
extern void func_8012C098(void);

void func_80184B24(s32 param_1)
{
    s32 r, a1, a2;
    r = ((s32 (*)(void))func_8012BEE8)();
    if (r == 1) {
        s32 d = param_1;
        if (*(s16 *)(d + 0x70) & 0x8000) { a1 = 0x40000; a2 = 0xC0000; }
        else { a1 = 0x9000; a2 = 0x20000; }
        if (func_801845EC(d, a1, a2 | 0x4000) == r) {
            return;
        }
    }
    if (func_8012C044(param_1) != 0) {
        ((void (*)(s32))func_8012C098)(param_1);
    }
}
