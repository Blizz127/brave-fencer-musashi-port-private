/* Native retail instruction export [8002D1F0,8002D240).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002D1F0 - byte-exact against retail at -O2 (tools/register_match.py). */

extern void func_8003B45C(s32 *);

extern s32 D_800A4ECC;
extern s32 D_800A4ED0;
extern u16 D_800A4ED4;
extern u16 D_800A4ED6;

void func_8002D1F0(s32 arg0) {
    s32 *v1 = &D_800A4ECC;
    *v1 = 1;
    D_800A4ED0 = (s16)arg0;
    D_800A4ED4 = 0;
    D_800A4ED6 = 0;
    func_8003B45C(v1);
}
