/* Main-exec range [8002AC98,8002AE60) from the SLUS executable.
 * SHA256(span)=6486f3e5c60efab611ca2ba456ef578c3bb9c885ec65d93f558a259cbaca869f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8002AC98 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define rand func_8005C49C

extern s32 func_800291B4(s32);
extern u16 D_800A6588[];
extern u8 D_8010F46C[];
extern u8 D_80078EBA;
void func_8002AC98(void)
{
register u16 *base __asm__("$20");
  s16 i;
  s16 val;
  s32 t;
  s32 r;
  s32 idx;
  s16 rc;
  s32 b;
  base = D_800A6588;
  if (D_80078EBA == 0)
  {
    for (i = 0; i < 0x40; i++)
    {
      t = func_800291B4(((s16) i) + 0x63) & 0xF;
      if (t != 0)
      {
        r = rand() & 0x1F;
        switch (t)
        {
          case 1:
            rc = r;
            if ((rc != 0) && (rc != 0xB))
          {
            b = base[i] - 0xB;
            { s32 xt = r + b; val = xt; }
          }
          else
          {
            val = ((s16) base[i]) >> 1;
          }
            break;

          case 2:
            if (r != 0)
          {
            b = base[i] - 0xB;
            { s32 xt = r + b; val = xt; }
          }
            break;

          case 3:
            rc = r;
            if ((rc != 0) && (rc != 0xB))
          {
            b = base[i] - 0xB;
            { s32 xt = r + b; val = xt; }
          }
          else
          {
            val = base[i] * 2;
          }
            break;

        }

        idx = i + 1;
        if (val < (*((s16 *) (&D_8010F46C[idx * 8]))))
        {
          base[i] = *((s16 *) (&D_8010F46C[idx * 8]));
        }
        else
          if (((*((s16 *) (&D_8010F46C[idx * 8]))) * 4) < val)
        {
          rc = 4;
          base[i] = (*((s16 *) (&D_8010F46C[idx * 8]))) * rc;
        }
        else
        {
          base[i] = val;
        }
      }
    }

  }
}
