/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80174604 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801150F8;
extern void func_80174630(void);

void func_80174604(void) {
    D_801150F8 = 1;
    func_80174630();
}
