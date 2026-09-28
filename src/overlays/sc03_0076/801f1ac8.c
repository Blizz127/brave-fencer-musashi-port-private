/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F1AC8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_801F1DA0(void *a0);
extern s32 D_801F9DCC;

s32 func_801F1AC8(s32 param_1) {
    D_801F9DCC = 0;
    ((void (*)(void *, s32))func_8016EDEC)((void *)func_801F1DA0, 0x1000000);
    *(s32 *)(param_1 + 0x28) = 16;
    *(u8 *)(param_1 + 0x15) = *(u8 *)(param_1 + 0x15) + 1;
    return 0;
}
