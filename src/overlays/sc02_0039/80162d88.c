/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80162D88 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80013F3C(s32 a0);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800126C4(s32 a0, s32 a1);
extern void func_800123F0(s32 a0, s32 a1);

void func_80162D88(s32 *a0) {
    s16 *s0 = (s16 *)a0[8];
    s32 s1 = (s32)s0 + 0x34;
    func_80013F3C(s1);
    func_80012558(s1, s0[9]);
    func_800126C4(s1, s0[8]);
    func_800123F0(s1, s0[10]);
}
