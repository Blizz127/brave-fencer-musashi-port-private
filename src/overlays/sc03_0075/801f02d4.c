/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F02D4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801F6CAC;
extern s32 D_801F6CA8;

void func_801F02D4(void *a0) {
    extern s32 D_801F6CA8;
    extern s32 D_801F6CAC;
    register s32 v0 __asm__("$2");
    register s32 p __asm__("$4");
    v0 = D_801F6CA8;
    *(s16 *)((s32)a0 + 0xFC) = 0;
    p = D_801F6CAC;
    *(s16 *)(v0 + 0xFC) = 2;
    *(s16 *)(p + 0xFC) = 0;
}
