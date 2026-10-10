/* sc01_0077: func_80142BB4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 *ot; u32 pad[4]; } Env_1412A8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_1412A8;
typedef struct { u32 tag; u32 w1; u32 w2; u32 w3; } Prim_1412A8;
extern u16 D_80115116;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern short D_800B9A02;
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern short D_800B9A02;
extern u16 D_80115116;
extern short D_800B9A02;
extern u16 D_80115116;
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012AD44(s32 *a0, s16 a1);
extern void func_801439C0(u8 *a0);
extern void func_8012AD44(s32 *a0, s16 a1);
extern void func_8012C218(void *a0);
extern void func_8012C098(void);
void func_801439C0(u8 *a0);

void func_80142BB4(s32 * param_1, s32 param_2, s32 param_3)
{
  void *new_var;
  new_var = param_1;
  if ((*((s16 *) (new_var + 0xfc))) == 1)
  {
    if ((param_2 != ((char) 0)) || ((*((s16 *) (new_var + 0x100))) == 0))
    {
      *((u16 *) (new_var + 0x5c)) = (*((u16 *) (new_var + 0x5c))) & 0xfefe;
      *((u32 *) ((*((s32 *) (new_var + 0x20))) + 4)) = (*((u32 *) ((*((s32 *) (new_var + 0x20))) + 4))) | 0x80000000;
      func_801439C0(*((u8 **) (new_var + 0xcc)));
      func_8012AD44((s32 *) new_var, param_3);
    }
  }
  else
    if ((param_2 != 0) || ((*((s16 *) (new_var + 0x100))) == 0))
  {
 do { func_8012C218(new_var = (void *) new_var); } while (0);
  }
  else
  {
    ((void (*)(void *)) func_8012C098)((void *) new_var);
  }
}
