/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017CE1C - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_800167F0(int arg);
extern s32 func_800167F0(s32 a0);

s32 func_8017CE1C(void) {
    return (func_800167F0(0) & 0xffff) != 0;
}
