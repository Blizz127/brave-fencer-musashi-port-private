/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801729B0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80174684(void *);
extern s16 D_80126B30;
extern s32 func_801729F0();
extern s16 D_80126B34;
extern s16 D_80126B32;

void func_801729B0(s32 a0) {
    D_80126B34 = a0;
    D_80126B30 = 0;
    D_80126B32 = 0;
    func_80174684((void *)func_801729F0);
}
