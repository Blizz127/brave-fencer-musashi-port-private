/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80177340 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u32   func_801783D0(s32, s32);
extern u32 func_801783D0(s32 a0, s32 a1);
extern void func_801778A8(int param_1, unsigned int param_2, short param_3, short param_4);
extern u16 D_8011F830;
extern u16 D_8011F82E;

void func_80177340(s32 a0) {
    s32 v0;
    a0 += 0x50;
    func_801778A8(a0, (s16)func_801783D0(D_8011F830, 4), 3, 0xFF);
    a0 += 0x3C;
    func_801778A8(a0, (s16)func_801783D0(D_8011F82E, 4), 3, 0xFF);
    a0 += 0x3C;
    *(s16 *)(a0 + 0xC) = (u32)(D_8011F830 * 10355) >> 15;
    a0 += 0x14;
    v0 = ((s32)(D_8011F82E * 10355) << 1) >> 16;
    *(s16 *)(a0 + 0xC) = v0;
    *(s16 *)(a0 + 0x20) = v0 + 2;
}
