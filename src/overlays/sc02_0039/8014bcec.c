/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014BCEC - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80078EB6;

s32 func_8014BCEC(s32 a0, s32 a1)
{
    u16 v;
    v = D_80078EB6 + a1;
    D_80078EB6 = v;
    if (v >= 0x663) {
        D_80078EB6 = 0x662;
    }
}
