/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801733CC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8016F30C(void);
extern s32 func_80174650(s32);

void func_801733CC(s32 a0) {
    func_8016F30C();
    func_80174650(a0);
}
