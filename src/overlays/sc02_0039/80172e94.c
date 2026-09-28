/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80172E94 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern u8 D_800D5A34[];
extern s32 func_80174650(s32);
extern s16 D_80126B30;
extern void func_8017303C(void *);

void func_80172E94(void) {
    func_8017303C((void *)D_800D5A34);
    D_80126B30 = 0;
    func_80174650((s32)&D_80126B58);
}
