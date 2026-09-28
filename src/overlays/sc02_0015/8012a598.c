/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012A598 - byte-exact against retail at -O2 (tools/register_match.py). */
struct BigCopy;
struct BigCopy { s32 words[41]; };
extern struct BigCopy D_80126DB8;
extern u8 D_80127504;
extern s32 D_801151D4;

void func_8012A598(void *a0)
{
    D_80126DB8 = *(struct BigCopy *)D_801151D4;
    D_80127504 = 0x30;
}
