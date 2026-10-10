/* sc01_0077: func_801848CC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 (*D_8018AFB8[])();

s32 func_801848CC(s16 *a0) {
    return D_8018AFB8[(u16)a0[1]]();
}
