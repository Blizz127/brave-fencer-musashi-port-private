/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80178BB8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80178CBC(s32 a0, s32 a1);

void func_80178BB8(s32 a0, s32 a1) {
    func_80178BF8(a0, a1);
    func_80178CBC(a0, a1);
}
