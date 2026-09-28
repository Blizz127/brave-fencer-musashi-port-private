/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB184 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(s32);
extern void func_80146CA0(s32 a0);

void func_800CB184(void *a0) {
    extern void func_80146E90(s32 *a0, s32 a1);
    func_80146E90((s32 *)a0, *(s32 *)((s32)a0 + 0x50) << 2);
    func_80146CA0((s32)a0);
}
