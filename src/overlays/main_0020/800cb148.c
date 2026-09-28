/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB148 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154A74(s32 a0, s32 a1);
extern void func_8012A2F4(s32 a0);

void func_800CB148(s32 a0) {
    func_8012A2F4(a0);
    func_80154A74(a0, 0x11);
}
