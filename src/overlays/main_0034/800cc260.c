/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC260 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801599A4(void);
extern void func_80159B3C(void);

void func_800CC260(s32 a0) {
    func_801599A4();
    ((void (*)(s32))func_80159B3C)(a0);
}
