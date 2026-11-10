/* sc02_0037: func_801571C4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801555F4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct { s16 x, y, z, pad; } SVEC_80167AE0;
typedef struct { s16 x, y, z, pad; } SVEC_8016A290;
typedef void (*code)(unsigned short *);
struct Fr {
    u8 matrix[0x20];
    SVEC_80167AE0 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
struct Fr_80167AE0 {
    u8 matrix[0x20];
    SVEC_80167AE0 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
struct Fr_8016A290 {
    SVEC_8016A290 center;
    SVEC_8016A290 diff;
    s32 pos[3];
    s32 _pad1c;
    s16 mtx[32];
    SVEC_8016A290 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
typedef struct { s16 x, y, z, pad; } SVec_801670E4;
typedef struct {
               u16 cx, cy, cz;
               u16 _p06;
               u16 a8[4];
               s32 pos[3];
               s32 _p1C;
               SVec_801670E4 v[4];
               struct { u8 r, g, b, cd; } col[4];
               u32 code;
               s32 _p54;
               u8 m1[0x20];
               u8 m2[0x20];
} Fr_801670E4;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_801202A0[];
extern u8 D_80126720[];
extern s16 D_800B9A02;
extern u8 D_801152A8[];
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8) __asm__("func_801466F0");
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern s32 func_80135260(s32 arg0, s32 arg1, s16 *arg2, s16 *arg3);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern s32 func_8014C918(s32 a0, s32 a1);
extern int func_8014C918();
s32 func_8014C918(s32 a0, s32 a1);
extern u8 D_801152A8[];
extern s32 func_80135004(s32 a0, void *a1, s32 a2);
extern s32 func_80135260(s32 arg0, s32 arg1, s16 *arg2, s16 *arg3);
extern s32 func_8014C918(s32 a0, s32 a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern u8 D_801202A0[];
extern u8 D_801152A8[];
extern u8 D_80126720[];

u32 func_801571C4(s32 a0, u16 a1, u16 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, u16 a10, s32 a11, s32 a12)
{
  s16 sp18[4];
  u16 local_40;
  u16 local_38;
  u32 local_30;
  u32 ret;
  u32 counter;
  u32 s4val;
  s32 off;
  s32 r;
  ret = 0;
  ;
  local_38 = a10;
  r = ((s32 (*)(s32, s32, s32))func_80135004)(1, a3, a4);
  if (r != 0)
  {
    *((u8 *) a11) = (*((u16 *) (a4 + 6))) >> 13;
    *((u8 *) a12) = *((u16 *) (a4 + 6));
    ret = 2;
    __builtin_memcpy((void *) a6, D_801152A8, 8);
  }
  counter = 0;
  s4val = a1;
  local_30 = a2 & 0x8000;
  off = 0;
  do
  {
    u8 *e = &D_801202A0[off];
    s32 a1v;
    if (((((((*((u16 *) e)) != 0) && ((a1v = *((s32 *) (e + 0x58))) != 0)) && (((*((u32 *) (e + 0x5c))) & 0x8100) == 0x8000)) && ((*((u16 *) (e + 0x5e))) != 10)) && (((a9 & 0x80) != 0) || ((*((u16 *) (e + 0x5e))) != s4val))) && ((s4val != 0xd) || (((*((u16 *) (e + 0x5c))) & 0x2000) != 0)))
    {
      if (func_80135260(*((s32 *) (e + 0x20)), a1v, a3, a4) != 0)
      {
        if ((((*((u16 *) (e + 0x5c))) & 0x4000) != 0) || (((*((s16 *) (e + 0xae))) & local_38) != 0))
        {
          *((u8 *) a11) = func_8014C918(a0, *((u8 *) (e + 0x75)));
          *((u8 *) a12) = 0;
          __builtin_memcpy((void *) a6, D_801152A8, 8);
          ret |= 4;
          *((s32 *) a7) = (s32) e;
        }
        else
        {
          __builtin_memcpy(sp18, (void *) a4, 8);
          if (local_30 != 0)
          {
            sp18[3] = 1;
          }
          else
          {
            sp18[3] = 0;
          }
          func_8014C4AC((s32) e, a1, a2 & 0x7fff, sp18, *((s16 *) ((*((s32 *) (a0 + 0x20))) + 0x12)));
          __builtin_memcpy((void *) a5, D_801152A8, 8);
          *((s32 *) a7) = (s32) e;
          __builtin_memcpy((void *) a8, D_80126720, 8);
          ret |= 1;
          if ((a9 & 0x7f) != 0)
          {
            return ret;
          }
        }
      }
    }
    counter += 1;
    off += 0x10c;
  }
  while (counter < 0x60);
  return ret;
}
