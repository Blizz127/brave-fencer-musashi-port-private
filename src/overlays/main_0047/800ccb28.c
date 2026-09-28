/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCB28 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);

void func_800CCB28(void *a0) {
    void *s0 = a0;

    func_80146994(0x3B, (s32)s0, 0, 0);
    *(s16 *)((s32)s0 + 0x1C8) = 0xBA;
    func_801599A4(s0);
    func_80159B3C(s0);
}
