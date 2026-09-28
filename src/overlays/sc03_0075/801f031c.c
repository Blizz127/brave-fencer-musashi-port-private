/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F031C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801F6CAC;
extern s32 D_801F6CA8;

void func_801F031C(void *arg0) {
    extern s32 D_801F6CA8;
    extern s32 D_801F6CAC;
    s32 a = D_801F6CA8;
    s32 b = D_801F6CAC;
    *(s16 *)((s32)arg0 + 0xFC) = 0;
    *(s16 *)(a + 0xFC) = 0;
    *(s16 *)(b + 0xFC) = 0;
}
