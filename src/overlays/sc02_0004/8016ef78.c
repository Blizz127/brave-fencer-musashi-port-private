/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016EF78 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern void func_801726D0(void *a0);
extern s32 func_8016EFC8();

void func_8016EF78(s32 a0) {
    func_8016EFC8(a0);
    func_801726D0(&D_80126B58);
}
