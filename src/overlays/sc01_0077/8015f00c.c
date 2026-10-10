/* sc01_0077: func_8015F00C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void (*D_801894B4[])(void);

void func_8015F00C(s32 * param_1)
{
  void (*new_var)(void);
  u16 *new_var2;
  new_var2 = param_1;
  new_var2 = new_var2 + 1;
  new_var = D_801894B4[*new_var2];
  new_var();
}
