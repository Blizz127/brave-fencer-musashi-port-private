/* Overlay range [80140958,80140D68) from MAIN.CD member 0012.
 * SHA256(span)=e4e15e6d5e9ea4bfb92ef25ceec307d63522d42fc2081a9f7f203fc8a5008582.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80140958 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
typedef struct { s16 x; s16 y; } Hw4;
typedef struct { u16 f0; s16 f2; } Prim4;
typedef struct 
  {
    u32 *ot;
    u32 pad[4];
  } Env_80140958;

extern s16 func_8014168C(s16);
extern s32 *func_80140D68(s32 *, Prim4 *, s32, s32, s32);
/* func_80140958 -- MATCH (260 ins), verified by
 *   python3 tools/match_one.py func_80140958 --c .run/near6/wave23/func_80140958.c \
 *       --asm-subdir asm/ov_SC01_077/nonmatchings/ov_SC01_077
 *
 * Three levers took the seed from 6 -> 0 (see the numbered notes in the inner block):
 *   [L1] `m == i` (not `m == 3`)  -- keeps b[0] a RUNTIME value; `m == 3` let gcc
 *        const-fold it and materialise `li a3,3` / `li t3,12` instead of
 *        `addu a3,v1,zero` / `sll t3,v1,2`.
 *   [L2] one dead `__asm__ volatile("" :: "r"(j))` -- +1 weighted REG_N_REFS on j so
 *        global.c:594 allocno_compare ranks j above k (j -> $a2, k -> $a3).
 *   [L3] `t3v = m * 4` as an EXPLICIT preheader statement (instead of letting loop.c
 *        hoist D_8011516A[m]'s index) -- gives it a LUID *below* the three constant
 *        assignments, which is what puts `move a3,v1 / sll t3,v1,2` ahead of them in
 *        sched1's backward LUID tie-break.
 */
s32 *func_80140958(ot, i, n)
s32 *ot;
s16 i;
s16 n;
{

    extern short D_800B9A02;
    extern u16 D_80115110;
    extern u8 D_80115140[];
    extern s16 D_8011514E;
    extern u8 D_80115158[];
    extern Hw4 D_8011516A[];
    extern Prim4 D_8017F1F0[];
    extern Prim4 *D_8017F2E4[];
    extern u8 D_80115143;
    extern Prim4 D_8017F1A0[];
    extern s16 D_8017F700[];
    extern s16 D_8017F710[];
    extern u16 D_8017F220;
    extern u16 D_8017F222;
  extern Env_80140958 D_800AE7BC[];
  Prim4 *p;
  s16 t;
  s32 c3;
register u16 *a __asm__("$20");
register u16 *b __asm__("$21");
register u16 *c __asm__("$23");
register u16 *e __asm__("$22");
register u16 *pb __asm__("$10");
register u32 m24 __asm__("$8");
register u32 mhi __asm__("$9");
register s32 eight __asm__("$2");
  if (i < n)
  {
    c3 = 3;
    a = &D_80115110;
    b = a + 5;
    c = a + 3;
    e = &D_8017F222;
    do
    {
      if (((a[0] == 0) && (a[1] != c3)) && (a[1] < 6))
      {
        if (i == a[5])
        {
          ot = func_80140D68(ot, &D_8017F1A0[i], i, D_8017F700[a[3] & 7], 0);
        }
      }
      else
      {
        p = D_8017F2E4[i];
        if (((p != 0) && (i == b[0])) && (i != 6))
        {
          if ((i == 2) && ((*((s16 *) (b + 7))) != 0))
          {
            p = D_8017F1F0;
          }
          if (i != c3)
          {
            t = ((s32 (*)(s16)) func_8014168C)(i) * 2;
          }
          else
          {
            t = ((*((u8 *) (&D_8011514E))) - D_80115143) * 2;
          }
          ot = func_80140D68(ot, p, i, D_8017F710[c[0] & 7], t);
          if (((i == 2) && ((*((s16 *) (c + 9))) == 1)) && ((*((s16 *) (c + 12))) != 0))
          {
            ot = func_80140D68(ot, p, 2, 8, ((*((s16 *) (c + 12))) & 0xF) * 2);
          }
        }
      }
      if (i == c3)
      {
        s32 m = b[0];
        /* [L1] compare against `i`, NOT against the literal 3. */
        if ((m == i) && ((b[-2] & 8) != 0))
        {
          s16 j;
          s32 k;
          s32 t3v;
          u8 *q = ((u8 *) ot) + 0x14;
          s16 y;
          j = 0;
          k = m;
          t3v = m * 4;                  /* [L3] explicit, must sit before the 3 constants */
          pb = (u16 *) (&D_800B9A02);
          m24 = 0xFFFFFF;
          mhi = 0xFF000000;
          for (; j < 2; j++)
          {
            if (j == 0)
            {
              if (D_80115140[k] == 0)
              {
                continue;
              }
              q[-7] = 0x30;
              y = (*e) - 4;
            }
            else
            {
              s32 k2 = k * 2;
              if ((((s8 *) D_80115158)[k2] - ((s8 *) D_80115140)[k]) < 2)
              {
                continue;
              }
              q[-7] = 0x38;
              y = (*e) + 3;
            }
            *((s16 *) (q - 10)) = y;
__asm__("" ::: "memory");
            *((u32 *) ot) = 0x4000000;
            q[-8] = 0x78;
            *((u32 *) (q - 0x10)) = 0x64808080;
            *((s16 *) (q - 6)) = 0x4056;
            *((s16 *) (q - 0xC)) = (D_8017F220 + ((u16) *((u16 *) (((u8 *) D_8011516A) + t3v)))) + 0x4A;
            eight = 8;
            *((s16 *) (q - 2)) = eight;
            *((s16 *) (q - 4)) = eight;
            *((u32 *) ot) = ((*((u32 *) ot)) & mhi) | (D_800AE7BC[*pb].ot[2] & m24);
            {
register u32 *op __asm__("$4");
              op = D_800AE7BC[*pb].ot;
              op[2] = (op[2] & mhi) | (((u32) ot) & m24);
            }
            q += 0x14;
            ot += 5;
            __asm__ volatile("" :: "r"(j));   /* [L2] zero code, +1 ref on j */
          }

        }
      }
      i = i + 1;
    }
    while (i < n);
  }
  return ot;
}
