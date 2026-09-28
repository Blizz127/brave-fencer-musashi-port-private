/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80146014 - byte-exact against retail at -O2 (tools/register_match.py). */
#define MoveImage func_80059A80
extern void MoveImage(void *a0, s32 a1, s32 a2);

void func_80146014(s32 a0) {
    s32 *r = (s32 *)a0;
    if (r[3] == 0) {
        return;
    }
    do {
        MoveImage(r, r[2], r[3]);
        r += 4;
    } while (r[3] != 0);
}
