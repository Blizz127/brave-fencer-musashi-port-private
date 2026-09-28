/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB8C4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8012EFB8();

void func_800CB8C4(void *a0, void *a1) {
    func_80015978(*(s32 *)((s32)a0 + 0x4C) + 4, (s32 *)a1);
    func_8012EFB8(a1, a1);
}
