/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017250C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80172560(u8 *a0, u8 *a1);

int func_8017250C(short *a0, short *a1) {
    if (func_80172560(a0, a1) == 0) {
        return 0;
    }
    a0[3] = a1[0];    
    a0[7] = a1[2];    
    return 1;
}
