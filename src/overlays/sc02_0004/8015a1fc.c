/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015A1FC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015A2D8(s32);

void func_8015A1FC(s32 *a0) {
    func_80147078(a0, 1);
    func_8015A2D8(a0);
}
