/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015BFB0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32*, s16);
extern void func_8015C030(s32 *a0, s32 a1);

void func_8015BFB0(s32 *a0, s32 a1)
{
    func_80147078(a0, 0x4);
    func_8015C030(a0, a1);
}
