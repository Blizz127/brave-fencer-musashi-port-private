/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEC0 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAEC0(void *arg0) {
    extern s32 func_80165910(void);
    extern void func_801655E4(s32 arg0);
    extern void func_80147324(s32 arg0);

    if (func_80165910() == 0) {
        func_801655E4((s32)arg0);
        func_80147324(0x7B8);
    }
    *(u8 *)((s32)arg0 + 0x197) += 1;
}
