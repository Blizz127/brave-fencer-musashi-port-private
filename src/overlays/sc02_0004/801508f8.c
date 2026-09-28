/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801508F8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8015094C(s32 a0);

short func_801508F8(s32 a0)
{
  if ((*((u8 *) (a0 + 0x1BF))) != 0)
  {
    if ((*((u16 *) a0)) != 0x1A)
    {
      while (func_8015094C(a0) != 0)
      {
        ;
      }
    }
  }
}
