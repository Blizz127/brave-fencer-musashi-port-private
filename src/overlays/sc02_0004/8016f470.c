/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016F470 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80029124(s32, s32);
extern void func_80029124(s32 a0, s32 a1);

void func_8016F470(s32 a0) {
    func_80029124(a0 + 0x125, 0);
}
