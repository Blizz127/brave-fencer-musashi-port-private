/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80146DB8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);

void func_80146DB8(s32 *a0, s32 *a1) {
    func_80146DE8(a0, a1[0], a1[1], a1[2]);
}
