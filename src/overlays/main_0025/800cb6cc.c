/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB6CC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147364(u16 a0, s32 a1);
extern void func_8016634C(void *a0);
extern void func_80162CCC();

void func_800CB6CC(void *a0) {
    func_8016634C(a0);
    func_80147364(4, 0x649);
    func_80162CCC(a0);
}
