/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB7FC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801662F4(void);
extern void func_80162CCC(void);

void func_800CB7FC(s32 a0) {
    func_801662F4();
    ((void (*)(s32))func_80162CCC)(a0);
}
