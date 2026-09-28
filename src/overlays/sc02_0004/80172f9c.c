/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80172F9C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern void func_80154A74(s32 a0, s32 a1);
extern u8 D_800D46E4[];
extern void func_80154A74(int, int);
extern s32 func_80174650(s32);
extern s16 D_80126B30;
extern void func_8017303C(void *);

void func_80172F9C(void) {
    func_8017303C(D_800D46E4);
    func_80154A74((s32)&D_80126B58, 0x11);
    D_80126B30 = 0;
    func_80174650((s32)&D_80126B58);
}
