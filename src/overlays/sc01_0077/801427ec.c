/* sc01_0077: func_801427EC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
extern u16 D_801270C0;
extern void (*D_80187F64[])(int);

void func_801427EC(int param_1)
{
    if (*(s16 *)&D_801270C0 != 3) {
        D_80187F64[*(u16 *)(param_1 + 2)](param_1);
    }
}
