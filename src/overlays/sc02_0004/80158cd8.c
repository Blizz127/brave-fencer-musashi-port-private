/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80158CD8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern s32 func_80146E98(s32 a0);
extern void func_80147324(s32 arg0);
extern u16 func_801487F4(s32 *a0);
extern void func_80147324(s32 a0);

void func_80158CD8(s32 *a0) {
    s32 i = 1;
    if (func_801487F4(a0) & 0xF0) {
        i = 4;
    }
    while (i > 0) {
        if (func_80146E98((s32)a0)) {
            func_80147324(0x453);
            *(s32 *)((s32)a0 + 0x238) = 0x5B0000;
            func_80146CA0((void *)a0);
            i = 0;
        }
        i--;
    }
}
