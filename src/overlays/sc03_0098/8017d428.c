/* sc03_0098: func_8017D428 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_80147084(s32 *a0);
extern void func_801472B4(void *a0);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern void func_80147324(s32 arg0);
extern void func_8017D030(int);
extern void func_80147324(s32 arg0);
extern void func_8017D030(int);
extern void func_8017D030(int);
extern void func_8017D030(int);
void func_8017D030(int param_1);
extern void func_80147324(s32 arg0);
extern void func_8017D030(int);

void func_8017D428(int param_1)
{
  s32 v0;
  s32 *s1;
  u16 *ptr;
  v0 = *(s32 *)((char *)param_1 + 0x1C);
  s1 = (s32 *)*(s32 *)((char *)param_1 + 0x34);
  *(s32 *)((char *)param_1 + 0x1C) = v0 + 1;
  if (v0 < 0x20) {
    ptr = (u16 *)((char *)param_1 + 0x2A);
    *ptr = *ptr - 0x10;
  } else {
    u16 val = *(u16 *)((char *)param_1 + 0x2C);
    func_80147324((s32)val);
    func_80147084(s1);
    func_801472B4((void *)s1);
    *(s32 *)((char *)param_1 + 0x1C) = 0;
    ptr = (u16 *)((char *)param_1 + 2);
    *ptr = *ptr + 1;
  }
  func_8017D030(param_1);
}
