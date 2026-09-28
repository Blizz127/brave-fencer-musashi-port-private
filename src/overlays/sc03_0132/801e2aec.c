/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2AEC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801E2B14(s32 param_1, s16 *param_2);

void func_801E2AEC(s32 param_1) {
    extern s16 D_801274E8;
    func_801E2B14(param_1, &D_801274E8);
}
