/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F02F8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801F6CAC;
extern s32 D_801F6CA8;

void func_801F02F8(void *a0) {
    extern s32 D_801F6CA8;
    extern s32 D_801F6CAC;

    s32 var_v0 = D_801F6CA8;
    s32 var_v1 = D_801F6CAC;

    *(s16 *)((s32)a0 + 0xFC) = 0;
    *(s16 *)(var_v0 + 0xFC) = 0;
    *(s16 *)(var_v1 + 0xFC) = 1;
}
