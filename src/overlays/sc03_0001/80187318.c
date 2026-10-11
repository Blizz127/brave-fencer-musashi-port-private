/* sc03_0001: func_80187318 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32, s32);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012A828(s32 arg0, s32 arg1);

void func_80187318(void *a0)
{
  s32 v0 = *((s32 *) (((s32) a0) + 0xD0));
  func_8012A828(v0, *((s32 *) ((*((s32 *) ((v0 = (s32) a0) + 0xD0))) + 0x4)));
}
