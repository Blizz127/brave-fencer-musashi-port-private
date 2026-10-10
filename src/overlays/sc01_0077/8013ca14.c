/* sc01_0077: func_8013CA14 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef signed char s8;
typedef int s32;
extern s32 D_801D9568;
extern s32 D_801269D4;
extern s32 D_801269C8;
extern s32 D_801D9568;
extern s8 D_801D956C;
extern s8 D_801D956D;
extern s32 D_801D9568;
extern s8 D_801D956C;
extern s8 D_801D956D;
extern s32 D_801269C8;
extern s32 D_801269D4;

void func_8013CA14(void)
{
  int *base = &D_801D9568;
  signed char *p;
  unsigned char c;
  int t;
  if ((*base) != 0)
  {
    c = D_801D956D;
    if (c == 0)
    {
      p = (signed char *) ((((unsigned int) ((unsigned char) D_801D956C)) * 2) + D_801D9568);
      t = (int) (*p);
      D_801269D4 = t;
      D_801269C8 = t;
      D_801D956D = (unsigned char) p[1];
      D_801D956C = D_801D956C + 1;
      if (D_801D956D == 0)
      {
        D_801269D4 = 0;
        D_801269C8 = 0;
        D_801D956C = 0;
        *base = 0;
      }
    }
    else
    {
      D_801D956D = c - 1;
    }
  }
  return;
}
