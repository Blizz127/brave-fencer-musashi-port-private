/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801484B0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 *D_80126B78;
extern void func_801485B8(s32 a0, s32 a1, s32 a2);

void func_801484B0(s32 a0, s32 a1) {
    func_801485B8(*(s32 *)((s32)D_80126B78 + 0x20) - 0x10, a0, a1);
}
