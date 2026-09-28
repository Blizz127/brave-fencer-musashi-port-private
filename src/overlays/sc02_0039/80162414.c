/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80162414 - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_800167F0(int arg);
extern s32 func_800167F0(s32 a0);

s32 func_80162414(void) {
    return (func_800167F0(4) & 0xffff) != 0;
}
