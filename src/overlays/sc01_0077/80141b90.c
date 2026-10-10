/* sc01_0077: func_80141B90 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef struct { u32 *ot; u32 pad[4]; } Env_1412A8;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_1412A8;
typedef struct { u32 tag; u32 w1; u32 w2; u32 w3; } Prim_1412A8;
extern u8 D_800B9A15;
extern unsigned short D_80115112;
extern unsigned short D_80115112;
extern u16 D_80115116;
extern unsigned short D_80115112;
extern void func_8013FAF8(s16 a0, s16 a1);
extern short D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern unsigned short D_80115112;
extern void func_8013FAF8(s16 a0, s16 a1);
extern short D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern unsigned short D_80115112;
extern void func_8013FAF8(s16 a0, s16 a1);
extern short D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern u16 D_80115112;
extern unsigned short D_80115112;
extern short D_800B9A02;
extern unsigned short D_80115112;
extern s32 D_801151D0;
extern short D_800B9A02;
void func_8013FAF8(s16 arg0, s16 arg1);
extern short D_800B9A02;
extern short D_800B9A02;
extern int func_801412A8(int, int, int, int, int, int);
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
Prim_1412A8 *aF801412A8(Prim_1412A8 *out, int a1, int a2, int a3, u16 a4, u16 a5) __asm__("func_801412A8");
extern unsigned short D_80115112;
extern u16 D_80115112;
extern u8 D_800B9A15;
extern short D_800B9A02;
extern u16 D_80115112;
extern unsigned short D_80115112;
extern u16 D_80115116;
extern void func_8013FAF8(s16, s16);
extern short D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern u16 D_80115116;
extern u16 D_80115112;
extern u8 D_800B9A15;

void func_80141B90(void)
{
  volatile char pad;
  D_801151D0 = ((s32 *) D_801151C8)[*((u16 *) (&D_800B9A02))];
  ((void (*)(s32, s32))func_8013FAF8)(2, 3);
  if (D_80115116 == 0)
  {
    *((s8 *) (&D_800B9A15)) = 0;
    D_80115112 = D_80115112 + 1;
  }
}
