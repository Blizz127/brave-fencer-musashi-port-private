/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB5A8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58[];
extern void func_80162CCC(void);
extern s32 func_80165A20(s32 a0);

void func_800CB5A8(void) {
    func_80162CCC();
    func_80165A20((s32)&D_80126B58);
}
