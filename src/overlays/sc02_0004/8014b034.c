/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014B034 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014B084(void);
extern s16 D_80078E90;

void func_8014B034(s32 a0)
{
    register s16 *ptr = &D_80078E90;
    s16 v;
    v = ptr[1] + a0;
    ptr[1] = v;
    if (v >= 0x5A0) {
        ptr[1] = v - 0x5A0;
        func_8014B084();
    }
}
