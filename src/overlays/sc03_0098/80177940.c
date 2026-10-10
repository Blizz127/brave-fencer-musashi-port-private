/* sc03_0098: func_80177940 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
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
extern s32 func_80029504(void);
extern s32 func_80029504(void);
extern s32 func_80029504(void);

void func_80177940(u32 *p, u32 a_, u32 b_, u32 c_)
{
  int new_var;
register u32 a __asm__("$18");
register u32 b __asm__("$16");
register u32 c __asm__("$17");
register u32 v __asm__("$2");
  u32 *q;
  u32 *r;
  u32 flag;
register u32 n __asm__("$6");
  u32 nn;
  u32 t;
  u32 cl;
  u32 cs;
  u32 col;
  s16 i;
  new_var = a_;
  b = b_;
  c = c_;
  a = new_var;
  v = (u32) func_80029504();
  v = v - 10;
  v = v < 0x4b0;
  v = -v;
  v = v & 0xb4;
  c++;
  c--;
  cs = c << 16;
  p[0] = (((u32) (p - 5)) & 0xffffff) | 0x3000000;
  p[2] = cs | ((b + 0xf) & 0xffff);
  p[1] = 0x74808080;
  p[3] = (((v << 6) | 0x4016) << 16) | 0x3850;
  p += 5;
  q = p;
__asm__("" : "=r"(v) : "0"(v));
  cl = ((v << 6) | 0x4016) << 16;
  flag = 0x1000000;
  for (i = 0; i < 4; i++)
  {
    nn = (a << 16) >> 28;
    n = nn;
    if (((nn != 0) || (i == 3)) || (i == 1))
    {
      flag = 0;
    }
    q[0] = (((u32) (q - 5)) & 0xffffff) | 0x3000000;
    q[2] = (cs | (b & 0xffff)) | flag;
    col = 0x74808080;
    new_var = n * 8;
    q[1] = col;
    t = (new_var + 8) | 0x4000;
    q[3] = cl | t;
    q += 5;
    b += 8;
    a <<= 4;
    col = 0;
  }
  p = q;
  r = p;
__asm__("" : "=r"(r) : "0"(r));
  *((u16 *) (r - 8)) += 6;
  *((u16 *) (r - 3)) += 6;
}
