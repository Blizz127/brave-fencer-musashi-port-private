/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015BDD0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147078(s32*, s16);
extern s32 func_8015BE94();

void func_8015BDD0(s32 *a0) {
    func_80147078(a0, 3);
    ((s32 (*)(void *))func_8015BE94)(a0);
}
