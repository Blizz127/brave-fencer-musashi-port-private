/* sc01_0077: func_801429C4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
extern u16 D_801270C0;
extern u16 D_801270C0;
extern u16 D_801270C0;
extern u16 D_801270C0;
extern void (*D_80188208[])(void);

void func_801429C4(short *param_1)
{
  short new_var2;
  short *new_var;
  new_var2 = D_801270C0;
  if (new_var2 != 3)
  {
    new_var = param_1;
    D_80188208[(unsigned short) new_var[1]]();
  }
}
