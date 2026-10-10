/* sc01_0077: func_8014D820 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct {
    u16 guard;
    u16 pad;
    u16 field;
    u8 rest[14];
} Ent;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
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
typedef struct Rec801466F0 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Rec801466F0;
typedef struct
  {
    u16 x;
    u16 y;
    u16 z;
    u16 w;
    s32 pad[4];
    s32 f18;
    s32 f1C;
    s32 f20;
  } Desc;
typedef struct { u16 a, b, c, d; } V4U_8014C4AC;
extern s32 D_80126B58;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 D_80126B58;
extern u16 D_801152B8;
extern u16 D_8012693A;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3,
                          s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern u16 *func_80146750(u16 *param_1);
extern u16 *func_8014680C(short *param_1);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8)
    __asm__("func_801466F0");

unsigned short *func_80146750(unsigned short *a0);
unsigned short *func_8014680C(short *param_1);
extern s32 D_8011D030;
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 D_8011D030;
extern void func_80146AFC(void*);
void aF80146A6C(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6) __asm__("func_80146A6C");
void aF80146A6C(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6) __asm__("func_80146A6C");

extern s32 D_8011D030;
s32 aF80146AFC(void *arg0) __asm__("func_80146AFC");
s32 aF80146AFC(void *arg0) __asm__("func_80146AFC");

extern void func_80147364();
extern void func_80147364();
extern s16 D_800B9A08;
extern s32 D_80126B58;
extern void func_80015978(s32, s32*);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern void func_8002D4C8(s32 a0, s32 a1);
void aF80147364(u16 param_1, u16 param_2) __asm__("func_80147364");

extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_80012A60(s32 a0, s32 a1);
extern void func_80015978(int a0, int *a1);
extern int func_80133784(int a0, void *a1, int a2);
extern s32 D_80126B58;
extern s32 D_80126B58;
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32, s32);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015978(s32 a0, s32 *a1);
extern s16 D_800B9A08;
extern u16 *func_80146750(u16 *param_1);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80147364();
extern u16 *func_80146750(u16 *param_1);
extern s16 D_800B9A08;
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern s16 D_800B9A08;
extern u8 D_801202A0[];
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern s32 func_80012A60(s32 a0, s32 a1);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern u8 D_801202A0[];
extern s32 D_80126B58;
extern s32 D_8011D030;
extern void func_80146AFC(void *a0);
extern s32 D_80126B58;
extern s32 D_80126B58;
extern s32 D_80126B58;
extern s32 D_80126B58;
extern s16 D_800B9A08;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80146AFC(void *a0);
extern s32 D_8011D030;
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
extern s32 func_80012A60(s32 a0, s32 a1);
extern s32 func_80012A60(s32 a0, s32 a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
s32 aF8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4) __asm__("func_8014C4AC");
s32 aF8014C4AC() __asm__("func_8014C4AC");

extern s32 func_8004CFEC(s32 x, s32 y);
extern s32 func_8004CFEC(s32 dx, s32 dy);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80147364();
extern void func_80147364();
extern int func_80135A4C();
extern int func_80135888();
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
extern s16 D_800B9A08;
extern u8 D_801202A0[];
extern u8 D_8018876C[];
extern u8 D_801152A8[];
extern s16 D_801152AC;
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
extern s32 func_80012A60(s32 a0, s32 a1);
extern void func_800139C8(s32 a0, void *a1, void *a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_8014DCE0(s32 a0, s32 a1, s32 a2);
extern s32 func_80133784(s32 a0, void *a1, s32 a2);
s32 func_8014DCE0(s32 arg0, s32 arg1, s32 arg2);

s32 func_8014D820(s32 a0, u16 *a1, u16 *a2x)
{
  typedef struct
  {
    u16 x;
    u16 y;
    u16 z;
    u16 w;
  } V4;
  typedef struct EntD820
  {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 x;
    u16 f8;
    u16 y;
    u16 fC;
    u16 z;
    u8 p10[0x10];
    s32 f20;
    u8 p24[0x34];
    s32 f58;
    u16 f5C;
    u16 f5E;
    u8 p60[0x10C - 0x60];
  } Ent;
  int new_var2;
  s16 new_var3;
register u16 *a2 __asm__("$7");
  V4 out[3];
  V4 pos;
  Desc desc;
  Ent *ent;
  Ent *p;
  s32 dx;
  s32 dz;
  s32 ex;
  s32 ez;
  s32 r1;
  s32 r2;
  s32 r3;
  s32 ang;
  s32 x0;
  s32 y0;
  s32 z0;
  s32 tx;
  s32 tz;
  s32 ty;
  s32 r;
  s32 t;
  s32 u;
  s32 a0v;
__asm__ __volatile__("" : "=r"(a2) : "0"(a2x));
  t = a2[0];
  u = a1[0];
  dx = t - u;
a0v = a0;
  new_var3 = (s16) dx;
  t = a2[2];
  u = a1[2];
  dz = t - u;
  if (((s16) (dx | dz)) == 0)
  {
    goto fail;
  }
  desc.x = dx;
  desc.y = a2[1] - a1[1];
  desc.z = a2[2] - a1[2];
  ent = *((Ent **) (a0v + 0x170));
  if (ent->f0 == 0)
  {
    goto fail;
  }
  if ((ent->f5C & 0x1000) == 0)
  {
    goto fail;
  }
  if (ent->f58 == 0)
  {
    goto fail;
  }
  if (((s32 (*)(s32, s32, s32)) func_80135A4C)(ent->f20, ent->f58, (s32) a1) == 0)
  {
    goto fail;
  }
  ex = ent->x - (*((u16 *) (a0v + 6)));
  ez = ent->z - (*((u16 *) (a0v + 0xE)));
  r1 = (s16) func_8004CFEC((s16) dz, new_var3);
  r2 = (s16) func_8004CFEC((s16) ez, (s16) ex);
  r3 = (s16) func_80012A60(r1, r2);
  if (0x400 <= r3)
  {
    goto fail;
  }
  desc.f20 = 0;
  desc.f1C = 0;
  desc.f18 = 0;
  x0 = ent->x;
  pos.x = x0;
  y0 = ent->y;
  pos.y = y0;
  z0 = ent->z;
  tx = x0 + desc.x;
  pos.z = z0;
  tz = z0 + desc.z;
  desc.x = tx;
  desc.z = tz;
  ty = (y0 + desc.y) + 8;
  desc.y = ty;
  if (D_800B9A08 != 0x3008)
  {
    for (p = (Ent *) D_801202A0; p < (Ent *) (D_801202A0 + 0x6480); p++)
    {
      if (p == ent)
      {
        continue;
      }
      if (p->f0 == 0)
      {
        continue;
      }
      if (p->f5C == 0)
      {
        continue;
      }
      if (p->f58 == 0)
      {
        continue;
      }
      func_80135888(p->f20, p->f58, (s32) (&pos), (s32) (&desc));
    }
  }
  else
  {
    ang = func_8004CFEC(((s16) x0) - ((s16) tx), ((s16) z0) - ((s16) tz)) & 0xFFF;
    func_800139C8(ang, D_8018876C, &out[0]);
    func_800139C8((s16) (ang - 0x155), D_8018876C, &out[1]);
    func_800139C8((s16) (ang + 0x155), D_8018876C, &out[2]);
    out[0].x += pos.x;
    out[0].y = pos.y;
    out[0].z += pos.z;
    out[1].x += pos.x;
    out[1].y = pos.y;
    out[1].z += pos.z;
    out[2].x += pos.x;
    out[2].y = pos.y;
    out[2].z += pos.z;
    for (p = (Ent *) D_801202A0; p < (Ent *) (D_801202A0 + 0x6480); p++)
    {
      if (p == ent)
      {
        continue;
      }
      if (p->f0 == 0)
      {
        continue;
      }
      if (p->f5C == 0)
      {
        continue;
      }
      if (p->f58 == 0)
      {
        continue;
      }
      if (func_8014DCE0((s32) p, (s32) (&pos), (s32) (&out[0])) != 0)
      {
        __builtin_memcpy((void *) ((s32) (&desc)), (void *) ((s32) (&pos)), 8);
      }
    }
  }
  r = func_80133784(0, &pos, (s32) (&desc));
  if ((r == 0) || ((r == 0x2000) && (((*(u16 *) D_801152A8) | ((u16) D_801152AC)) == 0)))
  {
    ent->x = desc.x - desc.f18;
    ent->y = desc.y;
    ent->z = desc.z - desc.f20;
    desc.x -= pos.x;
    desc.y -= pos.y;
    desc.z -= pos.z;
    *((u16 *) (a0v + 6)) = a1[0] + desc.x;
    new_var2 = desc.y;
    new_var2 = new_var2 + 0x10;
    *((u16 *) (a0v + 0xA)) = a1[1] + new_var2;
    *((u16 *) (a0v + 0xE)) = a1[2] + desc.z;
  }
  else
  {
    *((u16 *) (a0v + 6)) = a1[0];
    *((u16 *) (a0v + 0xA)) = a1[1] + 0x10;
    *((u16 *) (a0v + 0xE)) = a1[2];
  }
  return 1;
  fail:
  *((s32 *) (a0v + 0x170)) = 0;
  return 0;
}
