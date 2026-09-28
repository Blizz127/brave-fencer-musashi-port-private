/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80172310 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern s32 *D_80126B78;
extern void func_80172358(u8 *a0, u8 *a1);

void func_80172310(u8 *a0) {
    func_80172358((u8 *)&D_80126B58, a0);
    *(u16 *)((u8 *)D_80126B78 + 0x12) = *(u16 *)(a0 + 6);
}
