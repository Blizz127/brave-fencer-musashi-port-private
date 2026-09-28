/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2AF4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801E2B1C(s32 param_1, s16 *param_2);

void func_801E2AF4(s32 param_1) {
    extern s16 D_801274E8;
    func_801E2B1C(param_1, &D_801274E8);
}
