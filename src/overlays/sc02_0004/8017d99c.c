/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D99C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80126B66;

void func_8017D99C(s32 *a0) {
        if (*(s16 *)((char *)a0 + 0xe) < *(s16 *)&D_80126B66) {
            *(s16 *)((char *)a0 + 0x2) = 0;
        }
    }
