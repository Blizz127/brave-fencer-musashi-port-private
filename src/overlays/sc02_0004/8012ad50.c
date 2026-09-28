/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012AD50 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_8012AD50(void * arg0)
{
    (*(  s16 * )((s8 *)( arg0 ) + (  0x34 )))  = 0;
    (*(  u16 * )((s8 *)( arg0 ) + (  2 )))  = (u16) ((*(  u16 * )((s8 *)( arg0 ) + (  2 )))  + 1);
}
