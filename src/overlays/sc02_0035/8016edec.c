/* SC02.CD member35: func_8016EDEC from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef s32 M2C_UNK;
extern s32 D_80126B58;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_80159B3C(void * a0);
extern s32 D_80126B58;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_8016EE94();
extern s32 D_80126B58;
void func_8016EE94(s32 a0, s32 a1);

void func_8016EDEC(s32 _arg0, s32 _arg1, s32 _arg2)
{
  unsigned short *new_var;
  if (1)
  {
    ((M2C_UNK (*)(void)) func_8016EE94)();
    new_var = &D_80126B58;
    if (((u32) ((*new_var) - 0x19)) >= 2U)
    {
      ((M2C_UNK (*)(u16 *)) func_801599A4)(&D_80126B58);
      ((M2C_UNK (*)(u16 *)) func_80159B3C)(&D_80126B58);
    }
  }
}
