/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EF964 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801EF98C(s32 param_1, s16 *param_2);

void func_801EF964(s32 param_1) {
    extern s16 D_801274E8;
    func_801EF98C(param_1, &D_801274E8);
}
