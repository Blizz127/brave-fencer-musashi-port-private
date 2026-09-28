/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEF8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014BB24(s32 a0, s32 a1, s32 a2);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);

void func_800CAEF8(void *a0) {
    func_8014BB24((s32)a0, 10, 1);
    func_801599A4(a0);
    func_80159B3C(a0);
}
