/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80149350 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);

void func_80149350(s32 arg0) {
    ((void (*)())func_8012F14C)(*(s32 *)(arg0 + 0x20) + 0x34);
}
