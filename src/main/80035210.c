/* Exact retail word export [80035210,80035270); verified against pinned EXE and asm. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80035210 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 D_80076218;

extern void func_8003C498(s32);
extern void func_8003C438(s32, s32); /* SpuWrite */

void func_80035210(s32 a0, s32 a1)
{
    register s32 v1 __asm__("$3");

    v1 = D_80076218;
    func_8003C498(v1);
    func_8003C438(a0, a1);
    v1 = D_80076218;
    D_80076218 = v1 + a1;
}
