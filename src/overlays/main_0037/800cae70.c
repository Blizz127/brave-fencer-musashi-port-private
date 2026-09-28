/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAE70 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_800183E0(s32 *a0);
extern s32 D_800CB95C;

void func_800CAE70(void) {
    extern s32 D_800CB6FC;
    extern s32 D_800CB73C;
    extern s32 D_800CB6BC;
    extern s32 D_800CB95C;

    func_800183E0(&D_800CB6FC);
    func_800183E0(&D_800CB73C);
    D_800CB95C = 0;
    func_800183E0(&D_800CB6BC);
}
