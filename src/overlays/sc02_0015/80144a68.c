/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80144A68 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012AD44(s32 *a0, s16 a1);

void func_80144A68(s32 *a0) {
    *(s16 *)a0 = 0xC6;
    func_8012AD44(a0, 0);
}
