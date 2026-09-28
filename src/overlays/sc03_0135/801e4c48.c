/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E4C48 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_801E4F30(void *a0);

s32 func_801E4C48(s32 param_1) {
    extern s32 D_801EAC68;

    D_801EAC68 = 0;
    ((void (*)(void *, s32))func_8016EDEC)((void *)func_801E4F30, 0x1000000);
    *(u8 *)(param_1 + 0x15) = *(u8 *)(param_1 + 0x15) + 1;
    *(s32 *)(param_1 + 0x28) = 0x10;
    return 0;
}
