/* sc03_0098: func_8017D378 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 arg0);

void func_8017D378(void *param_1)
{
  unsigned short temp_0x2E;
  unsigned short *ptr_0x2;
  temp_0x2E = *(unsigned short *)((unsigned char *)param_1 + 0x2E);
  func_80147324((s32)temp_0x2E);
  ptr_0x2 = (unsigned short *)((unsigned char *)param_1 + 0x2);
  *ptr_0x2 = *ptr_0x2 + 1;
}
