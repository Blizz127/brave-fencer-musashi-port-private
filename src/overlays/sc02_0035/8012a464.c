/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012A464 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { s32 w[8]; } Vec8;
extern s32 D_801151D4;
extern Vec8 D_80114F24;

void func_8012A464(void)
{
    D_80114F24 = *(Vec8 *)(*(s32 *)&D_801151D4 + 0x3C);
}
