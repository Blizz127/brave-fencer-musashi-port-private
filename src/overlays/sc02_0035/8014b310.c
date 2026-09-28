/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014B310 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80078ECC;
extern void func_8014B33C(void);

void func_8014B310(void) {
    func_8014B33C();
    D_80078ECC = 0x80000000;
}
