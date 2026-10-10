/* sc01_0077: func_8016EE40 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef s32 M2C_UNK;
extern s32 D_80126B58;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_80159B3C(void * a0);
extern s32 D_80126B58;
extern s32 D_80126B58;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 D_80126B58;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_8016EF78(s32 a0);
extern s32 D_80126B58;
void func_8016EF78(s32 a0);

void func_8016EE40(s32 _arg0, s32 _arg1, s32 _arg2)
{
  s32 *new_var;
  void (*new_var2)(void *a0);
  unsigned short new_var3;
  new_var = &D_80126B58;
  ((M2C_UNK (*)(void)) func_8016EF78)();
  new_var3 = *new_var;
  if (((u32) (new_var3 - 0x19)) >= 2U)
  {
    ((M2C_UNK (*)(u16 *)) func_801599A4)(&D_80126B58);
    new_var2 = func_80159B3C;
    ((M2C_UNK (*)(u16 *)) new_var2)(&D_80126B58);
  }
}
