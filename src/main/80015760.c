/* Exact retail word export for [80015760,80015908); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80015760 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct 
{
  u16 unk0;
  u16 x;
  u16 y;
  u16 unk6;
  s32 value;
  u8 flags;
} Obj_80015760;
extern u16 D_800AF7BC;
extern u16 D_800AF7BE;
extern u8 *D_800A5E60;
extern u8 D_80062B78[];
extern u32 func_80015A74(u32 param_1);
extern s16 *func_80015908(s32 a0, s32 a1);

void func_80015760(Obj_80015760 *obj, s32 *ot)
{
  s32 x0;
register u32 tx __asm__("$5");
  s32 y0;
  s32 flags;
  u32 value;
  u32 digits;
register s32 count __asm__("$2");
  u8 digitCount;
  u8 width;
  u32 tagHi;
  u32 color;
  u32 yWord;
register u32 tagCode __asm__("$21");
  s32 *pkt;
  tx = obj->x;
  x0 = ((s32) tx) - (D_800AF7BC >> 1);
  flags = obj->flags;
  y0 = ((s32) obj->y) - (D_800AF7BE >> 1);
  value = (u32) obj->value;
  count = flags & 0xF;
  digitCount = count;
  if (count == 0)
  {
    digitCount = 8;
  }
  if (flags & 0x40)
  {
    digits = func_80015A74(value);
  }
  else
  {
    digits = value;
  }
  width = 8;
  if (flags & 0x80)
  {
    y0++;
    y0--;
    width = 0x10;
  }
  tagHi = width;
  if (tagHi == 8)
  {
    tagHi = 0x74000000;
  }
  else
  {
    tagHi = 0x7C000000;
  }
  tagCode = 0x03000000;
  pkt = (s32 *) D_800A5E60;
  if (digitCount != 0)
  {
    color = tagHi | 0x00808080;
    yWord = (u32) (y0 << 16);
    do
    {
      u32 xLow;
      u32 idx;
      s32 tile;
      u16 *uvPtr;
      u32 uvc;
register u32 mask __asm__("$3");
      xLow = (u16) x0;
      x0 = width + x0;
      idx = (digits >> ((digitCount - 1) << 2)) & 0xF;
      tile = D_80062B78[idx];
      pkt[1] = (s32) color;
      digitCount--;
      pkt[2] = (s32) (xLow | yWord);
      uvPtr = func_80015908(tile, (u16) flags);   /* the caller's original prototype took u16: the target masks (andi) before the call */
      uvc = 0x40560000;
      pkt[3] = (s32) ((*uvPtr) | uvc);
      mask = 0x00FFFFFF;
      pkt[0] = (s32) (((*ot) & mask) | tagCode);
      *ot = (s32) (((u32) pkt) & mask);
      pkt += 4;
    }
    while (digitCount != 0);
  }
  D_800A5E60 = (u8 *) pkt;
}
