/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017051C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_800AE6DC;
extern void func_80171928(void *a0);
extern void func_80171928(void *);

void func_8017051C(void *a0) {
    *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) = D_800AE6DC;
    func_80171928(a0);
}
